
%{
#include "tokens.h"
char* string_clean(char*);
int string_check_length(char*);
char* char_clean(char*);
%}

%option nounput
%option noinput

%%
\/\*([^\*]|\*[^\/])*\*+\/	{}
\/\/[^\n]*\n				{}
array 						{return TOKEN_ARRAY;}
boolean						{return TOKEN_BOOLEAN;}
char						{return TOKEN_CHAR;}
else						{return TOKEN_ELSE;}
false						{return TOKEN_FALSE;}
for							{return TOKEN_FOR;}
function					{return TOKEN_FUNCTION;}
if							{return TOKEN_IF;}
integer						{return TOKEN_INTEGER;}
print						{return TOKEN_PRINT;}
return						{return TOKEN_RETURN;}
string						{return TOKEN_STRING;}
true						{return TOKEN_TRUE;}
void						{return TOKEN_VOID;}
while						{return TOKEN_WHILE;}
--							{return TOKEN_DECREMENT;}
\+\+						{return TOKEN_INCREMENT;}
!							{return TOKEN_NEGATION;}
\(							{return TOKEN_LPAREN;}
\)							{return TOKEN_RPAREN;}
\[							{return TOKEN_LBRACKET;}
\]							{return TOKEN_RBRACKET;}
\{							{return TOKEN_LCURLY;}
\}							{return TOKEN_RCURLY;}
\+							{return TOKEN_PLUS;}
-							{return TOKEN_MINUS;}
\^							{return TOKEN_EXPONENT;}
\*							{return TOKEN_STAR;}
\/							{return TOKEN_SLASH;}
%							{return TOKEN_MOD;}
\<							{return TOKEN_LT;}
>							{return TOKEN_GT;}
>=							{return TOKEN_GE;}
\<=							{return TOKEN_LE;}
==							{return TOKEN_EQ;}
!=							{return TOKEN_NE;}
&&							{return TOKEN_AND;}
\|\|						{return TOKEN_OR;}
:							{return TOKEN_COLON;}
;							{return TOKEN_SEMICOLON;}
,							{return TOKEN_COMMA;}
=							{return TOKEN_ASSIGN;}
\'([^\\]|\\.)\'				{yytext = char_clean(yytext);
									return TOKEN_CHAR_LITERAL;}
[0-9]+						{return TOKEN_INT_LITERAL;}
\"(\\.|[^\\"\n])*\"			{yytext = string_clean(yytext);
							 if (string_check_length(strdup(yytext))){
								return TOKEN_STRING_LITERAL;
							 } else{
								return TOKEN_LENGTH_ERROR;
							}
							}
[a-zA-Z_][A-Za-z_0-9]*		{if (strlen(yytext) < 256)
								return TOKEN_IDENTIFIER;
							 else
								return TOKEN_LENGTH_ERROR;}
[ \t\n]						
.							{return TOKEN_ERROR;}

%%

int yywrap() {
	return 1;
}

char* string_clean(char* string){
	char* lead = ++string + 1;
	char* rear = string;
	while (*lead != '\0'){
		lead++; rear++;
	}
	*rear = '\0';
	return string;
}

int string_check_length(char* string){
	char* lead = ++string + 1;
	char* rear = string;
	while (*lead != '\0'){
		if (*rear == '\\'){
			if (*lead == 'n'){
				*lead = '\n';
			} else if (*lead == '0'){
				*rear = '\0';
			}
			char* rearTemp = rear;
			char* leadTemp = lead;
			while (*rearTemp != 0){
				*rearTemp = *leadTemp;
				rearTemp++; leadTemp++;
			}
		}
		lead++; rear++;
	}
	*rear = '\0';
	if (strlen(string) < 254)
		return 1;
	else
		return 0;
}

char* char_clean(char* c){
	char* rear = ++c;
	char* head = ++c;
	if (*rear == '\\')
		head++;
	*head = '\0';
	return rear;
}
