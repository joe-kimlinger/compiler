#include "expr.h"
#include <stdlib.h>

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

struct expr * expr_create_string_literal( const char *str ){
	struct expr* e = malloc(sizeof(*e));
	e->kind = EXPR_STRING_LITERAL;
	e->right = 0;
	e->left = 0;
	e->string_literal = str;
	return e;
}

void expr_print(struct expr *e){
	if (!e) return;
	switch(e->kind){
		case EXPR_ADD:
			expr_print(e->left);
			printf(" + ");
			expr_print(e->right);
			break;
		case EXPR_SUB:
			expr_print(e->left);
			printf(" - ");
			expr_print(e->right);
			break;
		case EXPR_MUL:
			expr_print(e->left);
			printf(" * ");
			expr_print(e->right);
			break;
		case EXPR_DIV:
			expr_print(e->left);
			printf(" / ");
			expr_print(e->right);
			break;
		case EXPR_MOD:
			expr_print(e->left);
			printf(" %% ");
			expr_print(e->right);
			break;
		case EXPR_EXPONENT:
			expr_print(e->left);
			printf("^");
			expr_print(e->right);
			break;
		case EXPR_ASSIGN:
			expr_print(e->left);
			printf(" = ");
			expr_print(e->right);
			break;
		case EXPR_OR:
			expr_print(e->left);
			printf(" || ");
			expr_print(e->right);
			break;
		case EXPR_AND:
			expr_print(e->left);
			printf(" && ");
			expr_print(e->right);
			break;
		case EXPR_LT:
			expr_print(e->left);
			printf(" < ");
			expr_print(e->right);
			break;
		case EXPR_GT:
			expr_print(e->left);
			printf(" > ");
			expr_print(e->right);
			break;
		case EXPR_GE:
			expr_print(e->left);
			printf(" >= ");
			expr_print(e->right);
			break;
		case EXPR_LE:
			expr_print(e->left);
			printf(" <= ");
			expr_print(e->right);
			break;
		case EXPR_EQ:
			expr_print(e->left);
			printf(" == ");
			expr_print(e->right);
			break;
		case EXPR_NE:
			expr_print(e->left);
			printf(" != ");
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
			printf("-");
			expr_print(e->left);
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
			printf("\"%s\"", e->string_literal);
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
