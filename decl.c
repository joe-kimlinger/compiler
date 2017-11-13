#include "decl.h"
extern int typecheck_result;

struct decl * decl_create( char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next ){
	struct decl *d = malloc(sizeof(*d));
	d->name = name;
	d->type = t;
	d->value = v;
	d->code = c;
	d->next = next;
	return d;
}

void decl_print(struct decl *d, int indent){
	if (!d) return;
	int i;
	for (i = 0; i < indent; i++) printf("\t");
	printf("%s: ", d->name);
	type_print(d->type);
	if (d->code){
		printf(" =\n");
		for (i = 0; i < indent; i++) printf("\t");
		printf("{\n");
		stmt_print(d->code, indent + 1);
		for (i = 0; i < indent; i++) printf("\t");
		printf("}\n");
	}
	else {
		if (d->value){
			printf(" = ");
			expr_print(d->value);
		}
		printf(";");
		printf("\n");
	}
	if (d->next) decl_print(d->next, indent);
}

void decl_resolve( struct decl *d){
	if(!d) return;
	if(d->value) {
		expr_resolve(d->value);
	}

	symbol_t kind = scope_level() > 1 ?
		SYMBOL_LOCAL : SYMBOL_GLOBAL;
	d->symbol = symbol_create(kind,d->type,d->name);

	struct symbol *temp = scope_lookup_current(d->name);
	if (temp){
		if (d->type->kind != TYPE_FUNCTION || !type_equals(d->type, temp->type)){
			printf("resolve error: %s was already declared in this scope\n", d->name);
			resolve_result = 0;
		} else {
			d->symbol = scope_lookup_current(d->name);
		}
	} else {
		if (d->type->kind == TYPE_FUNCTION && d->symbol->kind != SYMBOL_GLOBAL){
			printf("resolve error: function (%s) must be declared at global scope\n", d->name);
			resolve_result = 0;
		} else {
			scope_bind(d->name, d->symbol);
		}
	}
	if(d->code) {
		if (temp && temp->type->size){
			printf("resolve error: %s was already declared in this scope\n", d->name);
			resolve_result = 0;
		} else {
			scope_enter();
			param_list_resolve(d->type->params);
			stmt_resolve(d->code);
			scope_exit();
			d->type->size = expr_create_integer_literal(1);
		}
	}

	decl_resolve(d->next);
}

void decl_typecheck( struct decl *d )
{
	if (!d) return;
	struct type *t;
	if( d->value ) {
		t = expr_typecheck(d->value);

		if (d->symbol->type->kind == TYPE_ARRAY){
			// cannot initialize local arrays
			if (d->symbol->kind != SYMBOL_GLOBAL && d->value->kind == EXPR_ARRAY_INIT){
				printf("type error: array initilaizers cannot be used for local variables ");
				type_print(d->symbol->type);
				printf(" (%s)\n", d->name);
				typecheck_result = 0;
			}
			// Does initializer have right values
			if (!type_equals(t, d->symbol->type)){
				printf("type error: array initializer for (%s) does not match type ", d->name);
				type_print(d->symbol->type);
				printf("\n");
				typecheck_result = 0;
			} 
			if (d->type->size){
				// Is size constant
				if (d->type->size->kind != EXPR_INT_LITERAL){
					printf("type error: ");
					type_print(d->type);
					printf(" (");
					expr_print(d->value);
					printf(") must have constant size, not ");
					expr_print(d->type->size);
					printf("\n");
					typecheck_result = 0;
				} 
				// Is size equal to initializer
				if (d->type->size->literal_value != t->size->literal_value){
					printf("type error: array initializer for (%s) does not match array size of ", d->name); 
					expr_print(d->type->size);
					printf("\n");
					typecheck_result = 0;

				}
			} else {
				d->type->size = expr_create_integer_literal(t->size->literal_value);
			}
		} else {
		   	if(!type_equals(t,d->symbol->type)) {
				printf("type error: value ");
				type_print(t);
				printf(" (");
				expr_print(d->value);
				printf(") does not match variable declared as type ");
				type_print(d->symbol->type);
				printf("\n");
				typecheck_result = 0;
			}
			if(d->symbol->kind == SYMBOL_GLOBAL){
			   if ((d->symbol->type->kind == TYPE_BOOLEAN \
						   && d->value->kind != EXPR_BOOLEAN_LITERAL) \
					   || (d->symbol->type->kind == TYPE_CHARACTER \
						   && d->value->kind != EXPR_CHAR_LITERAL) \
					   || (d->symbol->type->kind == TYPE_STRING \
						   && d->value->kind != EXPR_STRING_LITERAL)){
					printf("type error: global ");
					type_print(d->symbol->type);
					printf(" (%s) must be intitialized as constant\n", d->name);
					typecheck_result = 0;
				} else if (d->symbol->type->kind == TYPE_INTEGER){
					if (d->value->kind == EXPR_NEGATIVE){
						if (d->value->left->kind != EXPR_INT_LITERAL){
							printf("type error: global ");
							type_print(d->symbol->type);
							printf(" (%s) must be intitialized as constant\n", d->name);
							typecheck_result = 0;
						}
					} else if (d->value->kind != EXPR_INT_LITERAL){
							printf("type error: global ");
							type_print(d->symbol->type);
							printf(" (%s) must be intitialized as constant\n", d->name);
							typecheck_result = 0;
						}
				}
			}
		}
	} else if (d->symbol->type->kind == TYPE_ARRAY){
		if (!d->type->size){
			printf("type error: ");
			type_print(d->type);
			printf(" (%s) must have size or initilizer\n", d->name);
			typecheck_result = 0;
		}
	} else if (d->symbol->type->kind == TYPE_FUNCTION){
		struct param_list *p = d->symbol->type->params;
		while (p){
			if (p->type->kind == TYPE_ARRAY){
				t = p->type->subtype;
				while (t->kind == TYPE_ARRAY){
					if (!t->size){
						printf("type error: function parameter ");
						type_print(p->type);
						printf(" (%s) must have a size for multi-dimensions\n", p->name);
					}
					t = t->subtype;
				}
			}
			p = p->next;
		}
	}
	if(d->code) {
		d->code->expect_return = d->symbol->type->subtype;
		stmt_typecheck(d->code);
	}
	decl_typecheck(d->next);
}

