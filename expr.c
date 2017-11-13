#include "expr.h"
extern int typecheck_result;

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right, int p){
	struct expr* e = malloc(sizeof(*e));
	e->kind = kind;
	e->left = left;
	e->right = right;
	e->precedence = p;
	return e;
}

struct expr * expr_create_name( const char *n ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_NAME;
	e->right = 0;
	e->left = 0;
	e->name = n;
	e->precedence = 100;
	return e;
}

struct expr * expr_create_boolean_literal( int c ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_BOOLEAN_LITERAL;
	e->right = 0;
	e->left = 0;
	e->literal_value = c;
	e->precedence = 100;
	return e;
}

struct expr * expr_create_integer_literal( int c ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_INT_LITERAL;
	e->right = 0;
	e->left = 0;
	e->literal_value = c;
	e->precedence = 100;
	return e;
}

struct expr * expr_create_character_literal( int c ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_CHAR_LITERAL;
	e->right = 0;
	e->left = 0;
	e->literal_value = c;
	e->precedence = 100;
	return e;
}

struct expr * expr_create_string_literal( char *str ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_STRING_LITERAL;
	e->right = 0;
	e->left = 0;
	e->string_literal = str;
	e->precedence = 100;
	return e;
}

void expr_print(struct expr *e){
	char *c;
	if (!e) return;
	switch(e->kind){
		case EXPR_INT_LITERAL:
			printf("%d", e->literal_value);
			return;
		case EXPR_CHAR_LITERAL:
			if (e->literal_value == '\n')
				printf("\'\\n\'");
			else
				printf("\'%c\'", e->literal_value);
			return;
		case EXPR_BOOLEAN_LITERAL:
			if (e->literal_value == 1)
				printf("true");
			else
				printf("false");
			return;
		case EXPR_STRING_LITERAL:
		    c = e->string_literal;
			printf("\"");
			while (*c){
				if (*c == '\n')
					printf("\\n");
				else
					printf("%c", *c);
				c++;
			}
			printf("\"");
			return;
		case EXPR_NAME:
			printf("%s", e->name);
			return;
		case EXPR_BRACKET_LIST:
			printf("[");
			break;
		case EXPR_NEGATION:
			printf("!");
			break;
		case EXPR_NEGATIVE:
			printf("-");
			break;
		default:
			break;
	}

	if (e->left && e->left->precedence < e->precedence)
		printf("(");
	expr_print(e->left);
	if (e->left && e->left->precedence < e->precedence)
		printf(")");

	switch (e->kind){
		case EXPR_ADD:
			printf("+");
			break;
		case EXPR_SUB:
			printf("-");
			break;
		case EXPR_MUL:
			printf("*");
			break;
		case EXPR_DIV:
			printf("/");
			break;
		case EXPR_MOD:
			printf("%%");
			break;
		case EXPR_EXPONENT:
			printf("^");
			break;
		case EXPR_ASSIGN:
			printf("=");
			break;
		case EXPR_OR:
			printf("||");
			break;
		case EXPR_AND:
			printf("&&");
			break;
		case EXPR_LT:
			printf("<");
			break;
		case EXPR_GT:
			printf(">");
			break;
		case EXPR_GE:
			printf(">=");
			break;
		case EXPR_LE:
			printf("<=");
			break;
		case EXPR_EQ:
			printf("==");
			break;
		case EXPR_NE:
			printf("!=");
			break;
		case EXPR_BRACKET_LIST:
			printf("]");
			break;
		case EXPR_FCALL:
			printf("(");
			break;
		case EXPR_ARRAY_INIT:
			printf("{");
			break;
		case EXPR_INCREMENT:
			printf("++");
			break;
		case EXPR_DECREMENT:
			printf("--");
			break;
		case EXPR_ARG:
			if (e->right){
			   printf(",");
			}
			break;
		default:
			break;
	}
	if (e->right && e->right->precedence < e->precedence)
		printf("(");
	expr_print(e->right);
	if ((e->right && e->right->precedence < e->precedence) || e->kind == EXPR_FCALL)
		printf(")");
	if (e->kind == EXPR_ARRAY_INIT)
		printf("}");
}

void expr_resolve( struct expr *e )
{
	if(!e) return;
	if( e->kind==EXPR_NAME ) {
		e->symbol = scope_lookup(e->name);
		if (e->symbol){
			switch(e->symbol->kind){
				case SYMBOL_GLOBAL:
					printf("%s resolves to global %s\n", e->name, e->name);
					break;
				case SYMBOL_LOCAL:
					printf("%s resolves to local %d\n", e->name, e->symbol->which);
					break;
				case SYMBOL_PARAM:
					printf("%s resolves to param %d\n", e->name, e->symbol->which);
					break;
			}
		} else {
			printf("resolve error: %s is not defined\n", e->name);
			resolve_result = 0;
		}
	} else {
		expr_resolve( e->left );
		expr_resolve( e->right );
	}
}

struct expr *expr_copy( struct expr *e){
	if (!e) return 0;
	struct expr *n = malloc(sizeof(struct expr));
	n->left = expr_copy(e->left);
	n->right = expr_copy(e->right);
	n->kind = e->kind;
	if (e->name)
		n->name = strdup(e->name);
	else
		n->name = 0;
	n->symbol = e->symbol;
	n->literal_value = e->literal_value;
	if (e->string_literal)
		n->string_literal = strdup(e->string_literal);
	else
		n->string_literal = 0;
	return n;

}

struct type * expr_typecheck( struct expr *e )
{
	if(!e) return 0;
	struct expr *t;
	int size = 0;
	struct type *lt = expr_typecheck(e->left);
	struct type *rt = expr_typecheck(e->right);
	struct type *result = 0;
	switch(e->kind) {
		case EXPR_INT_LITERAL:
			result = type_create(TYPE_INTEGER,0,0,0);
			break;
		case EXPR_STRING_LITERAL:
			result = type_create(TYPE_STRING,0,0,0);
			break;
		case EXPR_BOOLEAN_LITERAL:
			result = type_create(TYPE_BOOLEAN,0,0,0);
			break;
		case EXPR_CHAR_LITERAL:
			result = type_create(TYPE_CHARACTER,0,0,0);
			break;
		case EXPR_ADD:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot add ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER,0,0,0);
			break;
		case EXPR_SUB:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot subtract ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") from ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER, 0, 0,0);
			break;
		case EXPR_MUL:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot multiply ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") from ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER, 0, 0,0);
			break;
		case EXPR_DIV:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot divide ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") by ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER, 0, 0,0);
			break;
		case EXPR_MOD:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot mod ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") with ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER, 0, 0,0);
			break;
		case EXPR_ASSIGN:
			if (!type_equals(lt, rt)){
				printf("type error: cannot assign ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
				
			}
			if (lt->kind == TYPE_FUNCTION){
				printf("type error: cannot assign function (");
				expr_print(e->left);
				printf(")\n");
				typecheck_result = 0;
				
			}
			if (rt->kind == TYPE_FUNCTION){
				printf("type error: cannot assign function (");
				expr_print(e->left);
				printf(")\n");
				typecheck_result = 0;
				
			}
			result = type_copy(lt);
			break;
		case EXPR_OR:
			if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_AND:
			if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_LT:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_GT:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_GE:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_LE:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_EQ:
			if (lt->kind != rt->kind){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_NE:
			if (!type_equals(lt, rt) || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY){
				printf("type error: cannot compare ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN, 0, 0,0);
			break;
		case EXPR_FCALL:
			if (lt->kind != TYPE_FUNCTION){
				printf("type error: cannot call ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf("): not a function\n");
				typecheck_result = 0;
			}
			if (!param_list_typecheck(lt->params, e->right)){
				expr_print(e->left);
				printf("\n");
				typecheck_result = 0;
			}
			result = type_copy(lt->subtype);
			break;
		case EXPR_ARG:
			result = type_copy(lt);
			break;
		case EXPR_ARRAY_INIT:
			e = e->right;
			while (e){
				lt = expr_typecheck(e->left);
				rt = expr_typecheck(e->right);
				if (rt && !type_equals(lt, rt)){
					printf("type error: inconsistent array elements ");
					type_print(lt);
					printf(" (");
					expr_print(e->left);
					printf(") and ");
					type_print(rt);
					printf(" (");
					expr_print(e->right);
					printf("\n");
					typecheck_result = 0;
				}
				e = e->right;
				size++;
			}
			if (lt)
				result = type_create(TYPE_ARRAY, 0, lt, expr_create_integer_literal(size));
			else
				result = type_create(TYPE_ARRAY, 0, 0, expr_create_integer_literal(size));
			break;
		case EXPR_SUBSCRIPT:
			t = e->right;
			while (t->right && lt){
				if (lt->kind != TYPE_ARRAY){
					printf("type error: cannot index ");
					type_print(lt);
					printf(" (");
					expr_print(t->left);
					printf("): not an array\n");
					typecheck_result = 0;
					break;
				}
				t = t->right;
				lt = lt->subtype;
			}
			result = type_copy(lt->subtype);
			break;
		case EXPR_BRACKET_LIST:
			break;
		case EXPR_EXPONENT:
			if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER){
				printf("type error: cannot raise ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to the power of ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER,0,0,0);
			break;
		case EXPR_NEGATION:
			if (lt->kind != TYPE_BOOLEAN){
				printf("type error: cannot negate ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_BOOLEAN,0,0,0);
			break;
		case EXPR_NEGATIVE:
			if (lt->kind != TYPE_INTEGER){
				printf("type error: cannot make ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") negative\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER,0,0,0);
			break;
		case EXPR_INCREMENT:
			if (lt->kind != TYPE_INTEGER){
				printf("type error: cannot increment ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER,0,0,0);
			break;
		case EXPR_DECREMENT:
			if (lt->kind != TYPE_INTEGER){
				printf("type error: cannot decrement ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(")\n");
				typecheck_result = 0;
			}
			result = type_create(TYPE_INTEGER,0,0,0);
			break;
		case EXPR_NAME:
			if (e->symbol){
				result = type_copy(e->symbol->type);
			}
			break;

 
	}
	return result;
}
