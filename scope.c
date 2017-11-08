#include "scope.h"

struct scope_node *top = 0;

void scope_enter(){
	if (top){
		struct scope_node *temp = scope_node_create(top, 0, top->level + 1);
		top->next = temp;
		top = temp;
	}
}
void scope_exit(){
	if (top){
		hash_table_delete(top->table);
		top = top->prev;
		free(top->next);
	}
}
int scope_level(){
	if (top)
		return top->level;
	else
		return 1;
}

void scope_bind( const char *name, struct symbol *sym){
	if (!top){
		top = scope_node_create(0, 0, 1);
	}
	if (hash_table_insert(top->table, name, sym)){
		sym->which = top->var_count;
		top->var_count++;
	} else {
		printf("Unable to declare variable %s\n", name);
	}
}
struct symbol * scope_lookup( const char *name ){
	struct scope_node *curr = top;
	struct symbol *temp;
	while (curr){
		if ((temp = hash_table_lookup(curr->table, name)))
			return temp;
		else
			curr = curr->prev;
	}
	
	return 0;
}

struct symbol * scope_lookup_current( const char *name ){
	if (top)
		return hash_table_lookup(top->table, name);
	else
		return 0;
}

struct scope_node * scope_node_create(struct scope_node *p, struct scope_node *n, int level){
	struct scope_node *s = malloc(sizeof(struct scope_node));
	s->table = hash_table_create(0, 0);
	s->var_count = 0;
	s->level = level;
	s->prev = p;
	s->next = n;
	return s;
}
