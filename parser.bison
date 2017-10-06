%{
#include <stdio.h>
extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
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
%token TOKEN_IDENTIFIER
%token TOKEN_DECREMENT
%token TOKEN_INCREMENT
%token TOKEN_NEGATION
%token TOKEN_LENGTH_ERROR
%token TOKEN_ERROR

%%
program		: decl_list 
			;

decl_list	: decl decl_list
			| 
			;

decl		: TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_SEMICOLON
			| TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN stmt 
			;

type		: TOKEN_INTEGER
			| TOKEN_BOOLEAN
			| TOKEN_CHAR
			| TOKEN_STRING
			| TOKEN_VOID
			| TOKEN_ARRAY TOKEN_LBRACKET opt_expr TOKEN_RBRACKET type
			| TOKEN_FUNCTION type TOKEN_LPAREN param_list TOKEN_RPAREN
			;

expr		: expr TOKEN_ASSIGN expr2
			| expr2
			;

expr2		: expr2 TOKEN_OR expr3
			| expr3
			;

expr3		: expr3 TOKEN_AND expr4
			| expr4
			;

expr4		: expr4 TOKEN_LT expr5
			| expr4 TOKEN_GT expr5
			| expr4 TOKEN_GE expr5
			| expr4 TOKEN_LE expr5
			| expr4 TOKEN_EQ expr5
			| expr4 TOKEN_NE expr5
			| expr5
			;

expr5		: expr5 TOKEN_PLUS expr6
			| expr5 TOKEN_MINUS expr6
			| expr6
			;

expr6		: expr6 TOKEN_STAR expr7
			| expr6 TOKEN_SLASH expr7
			| expr6 TOKEN_MOD expr7
			| expr7
			;

expr7		: expr7 TOKEN_EXPONENT expr8
			| expr8
			;

expr8		: TOKEN_NEGATION expr9
			| TOKEN_MINUS expr9
			| expr9
			;

expr9		: expr9 TOKEN_INCREMENT
			| expr9 TOKEN_DECREMENT
			| expr10
			;

expr10		: TOKEN_IDENTIFIER expr11
			| TOKEN_INT_LITERAL
			| TOKEN_CHAR_LITERAL
			| TOKEN_STRING_LITERAL
			| TOKEN_TRUE
			| TOKEN_FALSE
			| TOKEN_LCURLY expr_list TOKEN_RCURLY
			| TOKEN_LPAREN expr TOKEN_RPAREN
			;

expr11		: TOKEN_LBRACKET expr TOKEN_RBRACKET bracket_list
			| TOKEN_LPAREN expr_list TOKEN_RPAREN
			|
			;

opt_expr	: expr
			|
			;

stmt		: stmt2
			| stmt3
			| TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt
			| decl
			;

stmt2		: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt
			| TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt4 TOKEN_ELSE stmt
			;

stmt3		: TOKEN_LCURLY stmt stmt_list TOKEN_RCURLY
			| expr TOKEN_SEMICOLON
			| TOKEN_RETURN opt_expr TOKEN_SEMICOLON
			| TOKEN_PRINT expr_list TOKEN_SEMICOLON
			;

stmt4		: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt4 TOKEN_ELSE stmt4
			| TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt4
			| stmt3
			;

stmt_list	: stmt stmt_list
			| 
			;

param_list	: TOKEN_IDENTIFIER TOKEN_COLON type 
			| param_list TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_COLON type 
			| 
			;

bracket_list: TOKEN_LBRACKET expr TOKEN_RBRACKET bracket_list
			| 
			;

expr_list	: expr 
			| expr TOKEN_COMMA expr_list
			| 
			;

%%

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}