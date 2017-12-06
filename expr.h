#ifndef EXPR_H
#define EXPR_H

#include "scope.h"
#include "scratch.h"
#include "label.h"
#include <stdlib.h>
#include "symbol.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_MOD,
	EXPR_ASSIGN,
	EXPR_OR,
	EXPR_AND,
	EXPR_LT,
	EXPR_GT,
	EXPR_GE,
	EXPR_LE,
	EXPR_EQ,
	EXPR_NE,
	EXPR_SUBSCRIPT,
	EXPR_BRACKET_LIST,
	EXPR_FCALL,
	EXPR_ARRAY_INIT,
	EXPR_EXPONENT,
	EXPR_NEGATION,
	EXPR_NEGATIVE,
	EXPR_INCREMENT,
	EXPR_DECREMENT,
	EXPR_INT_LITERAL,
	EXPR_CHAR_LITERAL,
	EXPR_STRING_LITERAL,
	EXPR_BOOLEAN_LITERAL,
	EXPR_ARG,
	EXPR_NAME
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	struct symbol *symbol;
	int literal_value;
	char * string_literal;
	int precedence;
	int reg;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right, int precedence);

struct expr * expr_create_name( const char *n );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_character_literal( int c );
struct expr * expr_create_string_literal( char *str );
void expr_string_literal_print(char *s);

void expr_print( struct expr *e );
void expr_resolve( struct expr *e);
struct type *expr_typecheck( struct expr *e);
struct expr *expr_copy( struct expr *e);
void expr_codegen (struct expr *e);

extern int resolve_result;
#endif
