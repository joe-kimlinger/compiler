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
		scope_bind(d->name, d->symbol);
	}
	if(d->value) {
		expr_resolve(d->value);
	}
	if(d->code) {
		scope_enter();
		param_list_resolve(d->type->params);
		stmt_resolve(d->code);
		scope_exit();
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
			printf("%d\n", t->size->literal_value);
			if (!type_equals(t, d->symbol->type->subtype)){
				printf("type error: array initializer (");
				expr_print(d->value);
				printf(") does not match type ");
				type_print(d->symbol->type);
				printf("\n");
				typecheck_result = 0;
			} else if (d->type->size->kind != EXPR_INT_LITERAL){
				printf("type error: ");
				type_print(d->type);
				printf(" (");
				expr_print(d->value);
				printf(") must have constant size, not ");
				expr_print(d->type->size);
				printf("\n");
				typecheck_result = 0;
			} else if (d->type->size->literal_value != t->size->literal_value){
				printf("type error: array initializer ");
				printf(" (");
				expr_print(d->value);
				printf(") does not match array size of ");
				expr_print(d->type->size);
				printf("\n");
				typecheck_result = 0;

			}
		} else if(!type_equals(t,d->symbol->type)) {
			printf("type error: value ");
			type_print(t);
			printf(" (");
			expr_print(d->value);
			printf(") does not match variable declared as type ");
			type_print(d->symbol->type);
			printf("\n");
			typecheck_result = 0;
		}
	}
	if(d->code) {
		d->code->expect_return = d->symbol->type->subtype;
		stmt_typecheck(d->code);
	}
	decl_typecheck(d->next);
}

