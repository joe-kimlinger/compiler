
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_EOF = 258,
     TOKEN_ARRAY = 259,
     TOKEN_BOOLEAN = 260,
     TOKEN_CHAR = 261,
     TOKEN_ELSE = 262,
     TOKEN_FALSE = 263,
     TOKEN_FOR = 264,
     TOKEN_FUNCTION = 265,
     TOKEN_IF = 266,
     TOKEN_INTEGER = 267,
     TOKEN_PRINT = 268,
     TOKEN_RETURN = 269,
     TOKEN_STRING = 270,
     TOKEN_TRUE = 271,
     TOKEN_VOID = 272,
     TOKEN_WHILE = 273,
     TOKEN_LPAREN = 274,
     TOKEN_RPAREN = 275,
     TOKEN_LBRACKET = 276,
     TOKEN_RBRACKET = 277,
     TOKEN_LCURLY = 278,
     TOKEN_RCURLY = 279,
     TOKEN_PLUS = 280,
     TOKEN_MINUS = 281,
     TOKEN_EXPONENT = 282,
     TOKEN_STAR = 283,
     TOKEN_SLASH = 284,
     TOKEN_MOD = 285,
     TOKEN_LT = 286,
     TOKEN_GT = 287,
     TOKEN_GE = 288,
     TOKEN_LE = 289,
     TOKEN_EQ = 290,
     TOKEN_NE = 291,
     TOKEN_AND = 292,
     TOKEN_OR = 293,
     TOKEN_COLON = 294,
     TOKEN_SEMICOLON = 295,
     TOKEN_COMMA = 296,
     TOKEN_INT_LITERAL = 297,
     TOKEN_CHAR_LITERAL = 298,
     TOKEN_ASSIGN = 299,
     TOKEN_COMMENT = 300,
     TOKEN_STRING_LITERAL = 301,
     TOKEN_IDENTIFIER = 302,
     TOKEN_DECREMENT = 303,
     TOKEN_INCREMENT = 304,
     TOKEN_NEGATION = 305,
     TOKEN_LENGTH_ERROR = 306,
     TOKEN_ERROR = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


