#include "expr.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = kind;
	e->left = left;
	e->right = right;
	return e;
}

struct expr * expr_create_name( const char *n ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_NAME;
	e->right = 0;
	e->left = 0;
	e->name = n;
	return e;
}

struct expr * expr_create_boolean_literal( int c ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_BOOLEAN_LITERAL;
	e->right = 0;
	e->left = 0;
	e->literal_value = c;
	return e;
}

struct expr * expr_create_integer_literal( int c ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_INT_LITERAL;
	e->right = 0;
	e->left = 0;
	e->literal_value = c;
	return e;
}

struct expr * expr_create_character_literal( int c ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_CHAR_LITERAL;
	e->right = 0;
	e->left = 0;
	e->literal_value = c;
	return e;
}

struct expr * expr_create_string_literal( char *str ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_STRING_LITERAL;
	e->right = 0;
	e->left = 0;
	e->string_literal = str;
	return e;
}

void expr_print(struct expr *e){
	char *c;
	if (!e) return;
	switch(e->kind){
		case EXPR_ADD:
			expr_print(e->left);
			printf("+");
			expr_print(e->right);
			break;
		case EXPR_SUB:
			expr_print(e->left);
			printf("-");
			expr_print(e->right);
			break;
		case EXPR_MUL:
			expr_print(e->left);
			printf("*");
			expr_print(e->right);
			break;
		case EXPR_DIV:
			expr_print(e->left);
			printf("/");
			expr_print(e->right);
			break;
		case EXPR_MOD:
			expr_print(e->left);
			printf("%%");
			expr_print(e->right);
			break;
		case EXPR_EXPONENT:
			expr_print(e->left);
			printf("^");
			expr_print(e->right);
			break;
		case EXPR_ASSIGN:
			expr_print(e->left);
			printf("=");
			expr_print(e->right);
			break;
		case EXPR_OR:
			expr_print(e->left);
			printf("||");
			expr_print(e->right);
			break;
		case EXPR_AND:
			expr_print(e->left);
			printf("&&");
			expr_print(e->right);
			break;
		case EXPR_LT:
			expr_print(e->left);
			printf("<");
			expr_print(e->right);
			break;
		case EXPR_GT:
			expr_print(e->left);
			printf(">");
			expr_print(e->right);
			break;
		case EXPR_GE:
			expr_print(e->left);
			printf(">=");
			expr_print(e->right);
			break;
		case EXPR_LE:
			expr_print(e->left);
			printf("<=");
			expr_print(e->right);
			break;
		case EXPR_EQ:
			expr_print(e->left);
			printf("==");
			expr_print(e->right);
			break;
		case EXPR_NE:
			expr_print(e->left);
			printf("!=");
			expr_print(e->right);
			break;
		case EXPR_PARENS:
			if (e->left && e->left->kind != EXPR_PARENS){
				printf("(");
				expr_print(e->left);
				printf(")");
			} else {
				expr_print(e->left);
			}
			break;
		case EXPR_SUBSCRIPT:
			expr_print(e->left);
			expr_print(e->right);
			break;
		case EXPR_BRACKET_LIST:
			printf("[");
			expr_print(e->left);
			printf("]");
			expr_print(e->right);
			break;
		case EXPR_FCALL:
			expr_print(e->left);
			printf("(");
			if (e->right) expr_print(e->right);
			printf(")");
			break;
		case EXPR_ARRAY_INIT:
			printf("{");
			if (e->left){
			   expr_print(e->left);
			   printf(" ");
			}
			printf("}");
			break;
		case EXPR_NEGATION:
			printf("!");
			expr_print(e->left);
			break;
		case EXPR_NEGATIVE:
			printf("(-");
			expr_print(e->left);
			printf(")");
			break;
		case EXPR_INCREMENT:
			expr_print(e->left);
			printf("++");
			break;
		case EXPR_DECREMENT:
			expr_print(e->left);
			printf("++");
			break;
		case EXPR_INT_LITERAL:
			printf("%d", e->literal_value);
			break;
		case EXPR_CHAR_LITERAL:
			printf("\'%c\'", e->literal_value);
			break;
		case EXPR_BOOLEAN_LITERAL:
			if (e->literal_value == 1)
				printf("true");
			else
				printf("false");
			break;
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
			break;
		case EXPR_ARG:
			if (e->left){
			   expr_print(e->left);
			   printf(", ");
			}
			if (e->right) expr_print(e->right);
			break;
		case EXPR_NAME:
			printf("%s", e->name);
			break;
		default:
			break;
	}
}

void expr_resolve( struct expr *e )
{
	if(!e) return;
	if( e->kind==EXPR_NAME ) {
		struct symbol *s = scope_lookup(e->name);
		if (s){
			switch(s->kind){
				case SYMBOL_GLOBAL:
					printf("%s resolves to global %s\n", e->name, e->name);
					break;
				case SYMBOL_LOCAL:
					printf("%s resolves to local %d\n", e->name, s->which);
					break;
				case SYMBOL_PARAM:
					printf("%s resolves to param %d\n", e->name, s->which);
					break;
			}
		} else {
			printf("resolve error: %s is not defined\n", e->name);
		}
	} else {
		expr_resolve( e->left );
		expr_resolve( e->right );
	}
}

struct expr * expr_typecheck( struct expr *e )
{
	if(!e) return;
	struct type *lt = expr_typecheck(e->left);
	struct type *rt = expr_typecheck(e->right);
	struct type *result;
	switch(e->kind) {
		case EXPR_INTEGER_LITERAL:
			result = type_create(TYPE_INTEGER,0,0);
			break;
		case EXPR_STRING_LITERAL:
			result = type_create(TYPE_STRING,0,0);
			break;
		case EXPR_BOOLEAN_LITERAL:
			result = type_create(TYPE_BOOLEAN,0,0);
			break;
		case EXPR_CHAR_LITERAL:
			result = type_create(TYPE_CHARACTER,0,0);
			break;
		case EXPR_VOID:
			result = type_create(TYPE_VOID,0,0);
			break;
		case EXPR_ADD:
			if (lt->kind != TYPE_INTEGER || rt->kind = TYPE_INTEGER){
				printf("type error: cannot add ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") to ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_SUB:
			if (lt->kind != TYPE_INTEGER || rt->kind = TYPE_INTEGER){
				printf("type error: cannot subtract ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") from ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_MULT:
			if (lt->kind != TYPE_INTEGER || rt->kind = TYPE_INTEGER){
				printf("type error: cannot multiply ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") from ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_DIVIDE:
			if (lt->kind != TYPE_INTEGER || rt->kind = TYPE_INTEGER){
				printf("type error: cannot divide ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") by ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_MOD:
			if (lt->kind != TYPE_INTEGER || rt->kind = TYPE_INTEGER){
				printf("type error: cannot mod ");
				type_print(lt);
				printf(" (");
				expr_print(e->left);
				printf(") with ");
				type_print(rt);
				printf(" (");
				expr_print(e->right);
				printf(")\n");
			}
			result = type_create(TYPE_INTEGER, 0, 0);
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
			}
			result = type_create(lt->kind, 0, 0);
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
			}
			result = type_create(TYPE_BOOLEAN, 0, 0);
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
			}
			result = type_create(TYPE_BOOLEAN, 0, 0);
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
			}
			result = type_create(TYPE_INTEGER, 0, 0);
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
			}
			result = type_create(TYPE_INTEGER, 0, 0);
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
			}
			result = type_create(TYPE_INTEGER, 0, 0);
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
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_EQ:
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
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
		case EXPR_NE:
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
			}
			result = type_create(TYPE_INTEGER, 0, 0);
			break;
	}
}
