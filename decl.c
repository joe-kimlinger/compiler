#include "decl.h"
#include "type.h"
#include "expr.h"
#include "stmt.h"
#include <stdlib.h>

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
