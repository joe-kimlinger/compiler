#include "param_list.h"


struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
	struct param_list *p = malloc(sizeof(*p));
	p->name = name;
	p->type = type;
	p->next = next;
	return p;
}

void param_list_print( struct param_list *a ){
	if (!a) return;
	printf("%s: ", a->name);
	type_print(a->type);
	if (a->next){
		printf(", ");
		param_list_print(a->next);
	}
}

void param_list_resolve( struct param_list *a){
	while (a){
		struct symbol *s = symbol_create(SYMBOL_PARAM, a->type, a->name);
		scope_bind(a->name, s);
		a = a->next;
	}
}

struct param_list *param_list_copy(struct param_list *a){
	if (!a) return 0;
	struct param_list *n = malloc(sizeof(struct param_list));
	n->name = strdup(a->name);
	if (a->symbol){
		n->symbol = malloc(
}
