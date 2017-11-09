#include "symbol.h"
#include <stdlib.h>

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
	struct symbol *s = malloc(sizeof(*s));
	s->kind = kind;
	s->type = type;
	s->name = name;
	return s;
}

struct symbol *symbol_copy( struct symbol *s){
	if (!s) return 0;
	struct symbol *n = malloc(sizeof(struct symbol));
	n->kind = s->kind;
	n->which = s->which;
	n->type = type_copy(s->type);
	n->name = strdup(s->name);
	return n;
}
