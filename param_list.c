#include "param_list.h"


struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
	struct param_list *p = malloc(sizeof(*p));
	p->name = name;
	p->type = type;
	p->next = next;
	return p;
}

int param_list_length(struct param_list *p){
	if (!p) return 0;
	return 1 + param_list_length(p->next);
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
	n->type = type_copy(a->type);
	n->symbol = a->symbol;
	n->next = param_list_copy(a->next);
	return n;
}

int param_list_equals(struct param_list *l, struct param_list *r){
	if (!l && !r) return 1;
	if (!l || !r) return 0;
	if (type_equals(l->type, r->type) && param_list_equals(l->next, r->next))
		return 1;
	return 0;
}

void param_list_delete(struct param_list *l){
	if (!l) return;
	param_list_delete(l->next);
	free(l->name);
	type_delete(l->type);
	free(l);
}

int param_list_typecheck(struct param_list *p, struct expr *a){
	if (!p && !a) return 1;
	if (!p) {
		printf("type error: too many arguments in function ");
		return 0;
	}
	if (!a){
		printf("type error: too few arguments in function ");
		return 0;
	}
	if (a->right && type_equals(p->type, expr_typecheck(a->left))){
		return param_list_typecheck(p->next, a->right);
	} else if (!a->right && type_equals(p->type, expr_typecheck(a))){
		return 1; 
	} else {
		printf("type error: parameter ");
		expr_print(a->left);
		printf(" is not of type ");
		type_print(p->type);
		printf(" in call to function ");
		return 0;
	}
}

void param_list_codegen(struct param_list *p){
	if (!p) return;
}
