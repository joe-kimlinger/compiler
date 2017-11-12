#ifndef SCOPE_H
#define SCOPE_H 
#include "symbol.h"
#include "hash_table.h"

void scope_enter();
void scope_exit();
int scope_level();
void scope_bind( const char *name, struct symbol *sym);
struct symbol * scope_lookup( const char *name );
struct symbol * scope_lookup_current( const char *name );
struct scope_node * scope_node_create(struct scope_node *p, struct scope_node *n, int level);

struct scope_node{
	int level;
	int var_count;
	struct hash_table *table;
	struct scope_node *next;
	struct scope_node *prev;
};


#endif
