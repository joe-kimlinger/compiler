#include "tokens.h"
#include <stdlib.h>
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;


int main(int argc, char* argv[]){
	yyin = fopen(argv[2], "r");
	if (!yyin){
		printf("Could not open %s!\n", argv[2]);
		return 1;
	}

	while(1){

		token_t t = yylex();
		switch (t){
			case TOKEN_ARRAY:
				printf("ARRAY\n");
				break;
			case TOKEN_BOOLEAN:
				printf("BOOLEAN\n");
				break;
			case TOKEN_CHAR:
				printf("CHAR\n");
				break;
			case TOKEN_ELSE:
				printf("ELSE\n");
				break;
			case TOKEN_FALSE:
				printf("FALSE\n");
				break;
			case TOKEN_FOR:
				printf("FOR\n");
				break;
			case TOKEN_FUNCTION:
				printf("FUNCTION\n");
				break;
			case TOKEN_IF:
				printf("IF\n");
				break;
			case TOKEN_INTEGER:
				printf("INTEGER\n");
				break;
			case TOKEN_PRINT:
				printf("PRINT\n");
				break;
			case TOKEN_RETURN:
				printf("RETURN\n");
				break;
			case TOKEN_STRING:
				printf("STRING\n");
				break;
			case TOKEN_TRUE:
				printf("TRUE\n");
				break;
			case TOKEN_VOID:
				printf("VOID\n");
				break;
			case TOKEN_WHILE:
				printf("WHILE\n");
				break;
			case TOKEN_DECREMENT:
				printf("DECREMENT\n");
				break;
			case TOKEN_INCREMENT:
				printf("INCREMENT\n");
				break;
			case TOKEN_NEGATION:
				printf("NEGATION\n");
				break;
			case TOKEN_LPAREN:
				printf("LPAREN\n");
				break;
			case TOKEN_RPAREN:
				printf("RPAREN\n");
				break;
			case TOKEN_LSQBRACKET:
				printf("LSQBRACKET\n");
				break;
			case TOKEN_RSQBRACKET:
				printf("LSQBRACKET\n");
				break;
			case TOKEN_LBRACKET:
				printf("RBRACKET\n");
				break;
			case TOKEN_RBRACKET:
				printf("RBRACKET\n");
				break;
			case TOKEN_PLUS:
				printf("PLUS\n");
				break;
			case TOKEN_MINUS:
				printf("MINUS\n");
				break;
			case TOKEN_EXPONENT:
				printf("EXPONENT\n");
				break;
			case TOKEN_STAR:
				printf("STAR\n");
				break;
			case TOKEN_SLASH:
				printf("SLASH\n");
				break;
			case TOKEN_MOD:
				printf("MOD\n");
				break;
			case TOKEN_LT:
				printf("LT\n");
				break;
			case TOKEN_GT:
				printf("GT\n");
				break;
			case TOKEN_GE:
				printf("GE\n");
				break;
			case TOKEN_LE:
				printf("LE\n");
				break;
			case TOKEN_EQ:
				printf("EQ\n");
				break;
			case TOKEN_NE:
				printf("NE\n");
				break;
			case TOKEN_AND:
				printf("AND\n");
				break;
			case TOKEN_OR:
				printf("OR\n");
				break;
			case TOKEN_COLON:
				printf("COLON\n");
				break;
			case TOKEN_SEMICOLON:
				printf("SEMICOLON\n");
				break;
			case TOKEN_COMMA:
				printf("COMMA\n");
				break;
			case TOKEN_ASSIGN:
				printf("ASSIGN\n");
				break;
			case TOKEN_CHARACTER_LITERAL:
				printf("CHARACTER_LITERAL %s\n", yytext);
				break;
			case TOKEN_INTEGER_LITERAL:
				printf("INTEGER_LITERAL %s\n", yytext);
				break;
			case TOKEN_STRING_LITERAL:
				printf("STRING_LITERAL %s\n", yytext);
				break;
			case TOKEN_IDENTIFIER:
				printf("IDENTIFIER %s\n", yytext);
				break;
			case TOKEN_EOF:
				exit(0);
				break;
			case TOKEN_ERROR:
				fprintf(stderr, "%s: scan error: %s is not a valid character\n", argv[2], yytext);
				exit(1);
			case TOKEN_LENGTH_ERROR:
				fprintf(stderr, "%s: scan error: token is too long\n", argv[2], yytext);
				exit(1);
		}
	}
}
