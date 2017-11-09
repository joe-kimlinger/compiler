#include "decl.h"

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
	scope_bind(d->name,d->symbol);
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
	struct type *t;
	if( d->value ) {
		t = expr_typecheck(d->value);
		if(!type_equals(t,d->symbol->type)) {
			/* display an error */
		}
	}
	if(d->code) {
		stmt_typecheck(d->code);
	}
}

