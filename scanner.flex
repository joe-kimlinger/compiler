
%{
#include "tokens.h"
%}


%%
\/\*([^\*]|\*[^\/])*\*+\/	{return TOKEN_COMMENT;}
\/\/[^(\\n)]*\n				{return TOKEN_COMMENT;}
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
-!							{return TOKEN_NEGATION;}
\(							{return TOKEN_LPAREN;}
\)							{return TOKEN_RPAREN;}
\[							{return TOKEN_LSQBRACKET;}
\]							{return TOKEN_RSQBRACKET;}
\{							{return TOKEN_LBRACKET;}
\}							{return TOKEN_RBRACKET;}
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
\'([a-zA-Z0-9]|\\[A-Za-z0-9])\'	{yytext = char_clean(yytext);
									return TOKEN_CHARACTER_LITERAL;}
[0-9]+						{return TOKEN_INTEGER_LITERAL;}
\"(\\.|[^\\"\n])*\"			{if (strlen(yytext) <= 256){
								yytext = string_clean(yytext);
								return TOKEN_STRING_LITERAL;
							 } else{
								return TOKEN_LENGTH_ERROR;
							}
							}
[a-zA-Z_][A-Za-z_0-9]*		{if (strlen(yytext) <= 256)
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
	int length = 0;
	char* lead = ++string + 1;
	char* rear = string;
	while (*lead != 0){
		if (*rear == '\\' && *lead == 'n'){
			char* rearTemp = rear;
			char* leadTemp = lead;
			*lead = '\n';
			while (*rearTemp != 0){
				*rearTemp = *leadTemp;
				rearTemp++; leadTemp++;
			}
		}
		lead++; rear++;
	}
	*rear = '\0';
	return string;
}

char* char_clean(char* c){
	char* rear = ++c;
	char* head = ++c;
	if (*rear == '\\'){
		if (*head == 'n')
			*rear = '\n';
		else if (*head == '0')
			*rear = '\0';
		else 
			*rear = *head;
		*head = '\0';
	}
	return rear;
}
