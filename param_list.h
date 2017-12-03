
#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "type.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct expr;

struct param_list {
	char *name;
	struct type *type;
	struct symbol *symbol;
	struct param_list *next;
};

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next );
int param_list_length(struct param_list *p);
void param_list_print( struct param_list *a );
void param_list_resolve( struct param_list *a );
int param_list_equals(struct param_list *l, struct param_list *r);
struct param_list *param_list_copy(struct param_list *l);
void param_list_delete(struct param_list *l);
int param_list_typecheck(struct param_list *p, struct expr *a);
void param_list_codegen(struct param_list *p);

#endif
