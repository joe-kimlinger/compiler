#include "symbol.h"
#include <stdlib.h>

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
	struct symbol *s = malloc(sizeof(*s));
	s->kind = kind;
	s->type = type;
	s->name = name;
	s->param_count = 0;
	return s;
}

const char* symbol_codegen( struct symbol *s ){
	static char str[256];
	if (s->kind == SYMBOL_GLOBAL){
		return s->name;
	} else {
		snprintf(str, 256, "-%d(%%rbp)", (s->which + 1 + s->param_count) * 8);
		return str;
	}
}
