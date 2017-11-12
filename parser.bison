%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decl.h"
#include "expr.h"
#include "param_list.h"
#include "stmt.h"
#include "type.h"

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

struct decl * parser_result = 0;
%}

%token TOKEN_EOF
%token TOKEN_ARRAY
%token TOKEN_BOOLEAN
%token TOKEN_CHAR
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_IF
%token TOKEN_INTEGER
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_STRING
%token TOKEN_TRUE
%token TOKEN_VOID
%token TOKEN_WHILE
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACKET
%token TOKEN_RBRACKET
%token TOKEN_LCURLY
%token TOKEN_RCURLY
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_EXPONENT
%token TOKEN_STAR
%token TOKEN_SLASH
%token TOKEN_MOD
%token TOKEN_LT
%token TOKEN_GT
%token TOKEN_GE
%token TOKEN_LE
%token TOKEN_EQ
%token TOKEN_NE
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_COLON
%token TOKEN_SEMICOLON
%token TOKEN_COMMA
%token TOKEN_INT_LITERAL
%token TOKEN_CHAR_LITERAL
%token TOKEN_ASSIGN
%token TOKEN_COMMENT
%token TOKEN_STRING_LITERAL
%token TOKEN_DECREMENT
%token TOKEN_IDENTIFIER
%token TOKEN_INCREMENT
%token TOKEN_NEGATION
%token TOKEN_LENGTH_ERROR
%token TOKEN_ERROR

%union {
	struct decl *decl;
	struct stmt *stmt;
	struct type *type;
	struct expr *expr;
	struct param_list *param_list;
	char* name;
};

%type <decl> program decl_list decl assign_decl
%type <stmt> stmt stmt2 stmt3 stmt4 stmt_list
%type <type> type
%type <expr> expr expr2 expr3 expr4 expr5 expr6 expr7 expr8 expr9 expr10 expr11 opt_expr expr_list bracket_list expr_list2
%type <param_list> param_list
%type <name> ident


%%
program		: decl_list 
				{ parser_result = $1; }
			;

decl_list	: decl decl_list
				{ $1->next = $2; $$ = $1; }
			| 
				{ $$ = 0; }
			;

decl		: ident TOKEN_COLON type TOKEN_SEMICOLON
				{ $$ = decl_create($1, $3, 0, 0, 0); }
			| ident TOKEN_COLON TOKEN_FUNCTION type TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMICOLON
				{ $$ = decl_create($1, type_create(TYPE_FUNCTION, $6, $4, 0), 0, 0, 0); }
			| assign_decl
				{ $$ = $1; }
			;

assign_decl	: ident TOKEN_COLON TOKEN_FUNCTION type TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_ASSIGN TOKEN_LCURLY stmt_list TOKEN_RCURLY
				{ $$ = decl_create($1, type_create(TYPE_FUNCTION, $6, $4, 0), 0, $10, 0); }
			| ident TOKEN_COLON type TOKEN_ASSIGN expr TOKEN_SEMICOLON
				{ $$ = decl_create($1, $3, $5, 0, 0); }
			;

type		: TOKEN_INTEGER
				{ $$ = type_create(TYPE_INTEGER, 0, 0, 0); }
			| TOKEN_BOOLEAN
				{ $$ = type_create(TYPE_BOOLEAN, 0, 0, 0); }
			| TOKEN_CHAR
				{ $$ = type_create(TYPE_CHARACTER, 0, 0, 0); }
			| TOKEN_STRING
				{ $$ = type_create(TYPE_STRING, 0, 0, 0); }
			| TOKEN_VOID
				{ $$ = type_create(TYPE_VOID, 0, 0, 0); }
			| TOKEN_ARRAY TOKEN_LBRACKET opt_expr TOKEN_RBRACKET type
				{ $$ = type_create(TYPE_ARRAY, 0, $5, $3); }
			;

expr		: expr TOKEN_ASSIGN expr2
				{ $$ = expr_create(EXPR_ASSIGN, $1, $3); }
			| expr2
				{ $$ = $1; }
			;

expr2		: expr2 TOKEN_OR expr3
				{ $$ = expr_create(EXPR_OR, $1, $3); }
			| expr3
				{ $$ = $1; }
			;

expr3		: expr3 TOKEN_AND expr4
				{ $$ = expr_create(EXPR_AND, $1, $3); }
			| expr4
				{ $$ = $1; }
			;

expr4		: expr4 TOKEN_LT expr5
				{ $$ = expr_create(EXPR_LT, $1, $3); }
			| expr4 TOKEN_GT expr5
				{ $$ = expr_create(EXPR_GT, $1, $3); }
			| expr4 TOKEN_GE expr5
				{ $$ = expr_create(EXPR_GE, $1, $3); }
			| expr4 TOKEN_LE expr5
				{ $$ = expr_create(EXPR_LE, $1, $3); }
			| expr4 TOKEN_EQ expr5
				{ $$ = expr_create(EXPR_EQ, $1, $3); }
			| expr4 TOKEN_NE expr5
				{ $$ = expr_create(EXPR_NE, $1, $3); }
			| expr5
				{ $$ = $1; }
			;

expr5		: expr5 TOKEN_PLUS expr6
				{ $$ = expr_create(EXPR_ADD, $1, $3); }
			| expr5 TOKEN_MINUS expr6
				{ $$ = expr_create(EXPR_SUB, $1, $3); }
			| expr6
				{ $$ = $1; }
			;

expr6		: expr6 TOKEN_STAR expr7
				{ $$ = expr_create(EXPR_MUL, $1, $3); }
			| expr6 TOKEN_SLASH expr7
				{ $$ = expr_create(EXPR_DIV, $1, $3); }
			| expr6 TOKEN_MOD expr7
				{ $$ = expr_create(EXPR_MOD, $1, $3); }
			| expr7
				{ $$ = $1; }
			;

expr7		: expr7 TOKEN_EXPONENT expr8
				{ $$ = expr_create(EXPR_EXPONENT, $1, $3); }
			| expr8
				{ $$ = $1; }
			;

expr8		: TOKEN_NEGATION expr9
				{ $$ = expr_create(EXPR_NEGATION, $2, 0); }
			| TOKEN_MINUS expr9
				{ $$ = expr_create(EXPR_NEGATIVE, $2, 0); }
			| expr9
				{ $$ = $1; }
			;

expr9		: expr9 TOKEN_INCREMENT
				{ $$ = expr_create(EXPR_INCREMENT, $1, 0); }
			| expr9 TOKEN_DECREMENT
				{ $$ = expr_create(EXPR_DECREMENT, $1, 0); }
			| expr10
				{ $$ = $1; }
			;

expr10		: ident expr11
				{ $2->left = expr_create_name($1); $2->name = $1; $$ = $2; }
			| TOKEN_INT_LITERAL
				{ $$ = expr_create_integer_literal(atoi(yytext)); }
			| TOKEN_CHAR_LITERAL
				{ $$ = expr_create_character_literal(yytext[0]); }
			| TOKEN_STRING_LITERAL
				{ $$ = expr_create_string_literal(strdup(yytext)); }
			| TOKEN_TRUE
				{ $$ = expr_create_boolean_literal(0); }
			| TOKEN_FALSE
				{ $$ = expr_create_boolean_literal(1); }
			| TOKEN_LCURLY expr_list TOKEN_RCURLY
				{ $$ = expr_create(EXPR_ARRAY_INIT, $2, 0); }
			| TOKEN_LPAREN expr TOKEN_RPAREN
				{ $$ = expr_create(EXPR_PARENS, $2, 0); }
			;

expr11		: TOKEN_LBRACKET expr TOKEN_RBRACKET bracket_list
				{ $$ = expr_create(EXPR_SUBSCRIPT, 0, expr_create(EXPR_BRACKET_LIST, $2, $4)); }
			| TOKEN_LPAREN expr_list TOKEN_RPAREN
				{ $$ = expr_create(EXPR_FCALL, 0, $2); }
			|
				{ $$ = expr_create(EXPR_NAME, 0, 0); }
			;

opt_expr	: expr
				{ $$ = $1; }
			|
				{ $$ = 0; }
			;

stmt		: stmt2
				{ $$ = $1; }
			| stmt3
				{ $$ = $1; }
			| TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt
				{ $$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0); }
			| decl
				{ $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0); }
			;

stmt2		: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt
				{ $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0); }
			| TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt4 TOKEN_ELSE stmt
				{ $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7); }
			;

stmt3		: TOKEN_LCURLY stmt stmt_list TOKEN_RCURLY
				{ $2->next = $3; $$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $2, 0); }
			| expr TOKEN_SEMICOLON
				{ $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0); }
			| TOKEN_RETURN opt_expr TOKEN_SEMICOLON
				{ $$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0); }
			| TOKEN_PRINT expr_list TOKEN_SEMICOLON
				{ $$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0); }
			;

stmt4		: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt4 TOKEN_ELSE stmt4
				{ $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7); }
			| TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt4
				{ $$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0); }
			| stmt3
				{ $$ = $1; }
			;

stmt_list	: stmt stmt_list
				{ $1->next = $2; $$ = $1;}
			| 
				{ $$ = 0; }
			;

param_list	: ident TOKEN_COLON type 
				{ $$ = param_list_create($1, $3, 0); }
			| param_list TOKEN_COMMA ident TOKEN_COLON type 
				{ $1->next = param_list_create($3, $5, 0); $$ = $1; }
			| 
				{ $$ = 0; }
			;

bracket_list: TOKEN_LBRACKET expr TOKEN_RBRACKET bracket_list
				{ $$ = expr_create(EXPR_BRACKET_LIST, $2, $4); }
			| 
				{ $$ = 0; }
			;

expr_list	: expr expr_list2
				{ $$ = expr_create(EXPR_ARG, $1, $2); }
			| 
				{ $$ = 0; }
			;

expr_list2  : TOKEN_COMMA expr expr_list2
				{ $$ = expr_create(EXPR_ARG, $2, $3); }
			|
				{ $$ = 0; }
			;

ident		: TOKEN_IDENTIFIER
				{ $$ = strdup(yytext); }
			;

%%

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}
