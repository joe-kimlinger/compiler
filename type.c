#include "type.h"

struct type * type_create( type_kind_t kind, struct param_list *params, struct type *subtype , struct expr *size ){
	struct type *t =  malloc(sizeof(*t));
	t->kind = kind;
	t->params = params;
	t->subtype = subtype;
	t->size = size;
	return t;
}

void type_print(struct type *t){
	switch(t->kind){
		case TYPE_BOOLEAN:
			printf("boolean");
			break;
		case TYPE_CHARACTER:
			printf("char");
			break;
		case TYPE_INTEGER:
			printf("integer");
			break;
		case TYPE_STRING:
			printf("string");
			break;
		case TYPE_ARRAY:
			printf("array [");
			expr_print(t->size);
			printf("] ");
			type_print(t->subtype);
			break;
		case TYPE_FUNCTION:
			printf("function ");
			type_print(t->subtype);
			printf(" (");
			param_list_print(t->params);
			printf(")");
			break;
		case TYPE_VOID:
			printf("void");
			break;
		default:
			break;
	}
}

int type_equals( struct type *a, struct type *b )
{
	if( a->kind == b->kind ) {
		if (a->kind == TYPE_ARRAY){
			if (type_equals(a->subtype, b->subtype)){
				return true;
			}
		} else if (a->kind == TYPE_FUNCTION){
			if (type_equals(a->subtype, b->subtype) && param_list_equals(a->param_list, b->param_list))
				return true;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

struct type * type_copy( struct type *t )
{
	if (!t) return 0;
	struct type *n = malloc(sizeof(struct type));
	n->subtype = type_copy(t->subtype);
	n->param_list = param_list_copy(t->param_list);
	n->kind = t->kind;

	if (t->size){
		n->size = malloc(sizeof(struct expr));
		n->size = t->size;
	} else {
		n->size = 0;
	}
	return n;
}

void type_delete( struct type *t )
{
	if (!t) return;
	type_delete(t->subtype);
	param_list_delete(t->param_list);
	free(t->size);
	free(t);
}