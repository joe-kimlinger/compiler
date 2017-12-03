/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

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

#line 83 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    TOKEN_DECREMENT = 302,
    TOKEN_IDENTIFIER = 303,
    TOKEN_INCREMENT = 304,
    TOKEN_NEGATION = 305,
    TOKEN_LENGTH_ERROR = 306,
    TOKEN_ERROR = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "parser.bison" /* yacc.c:355  */

	struct decl *decl;
	struct stmt *stmt;
	struct type *type;
	struct expr *expr;
	struct param_list *param_list;
	char* name;

#line 185 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    91,    94,    97,    99,   101,   105,   107,
     111,   113,   115,   117,   119,   121,   125,   127,   131,   133,
     137,   139,   143,   145,   147,   149,   151,   153,   155,   159,
     161,   163,   167,   169,   171,   173,   177,   179,   183,   185,
     187,   191,   193,   195,   199,   201,   203,   205,   207,   209,
     211,   213,   215,   219,   221,   225,   228,   231,   233,   235,
     237,   241,   243,   247,   249,   251,   253,   257,   259,   261,
     265,   268,   271,   273,   276,   279,   282,   285,   288,   291,
     294,   297
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_EOF", "TOKEN_ARRAY",
  "TOKEN_BOOLEAN", "TOKEN_CHAR", "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FOR",
  "TOKEN_FUNCTION", "TOKEN_IF", "TOKEN_INTEGER", "TOKEN_PRINT",
  "TOKEN_RETURN", "TOKEN_STRING", "TOKEN_TRUE", "TOKEN_VOID",
  "TOKEN_WHILE", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACKET",
  "TOKEN_RBRACKET", "TOKEN_LCURLY", "TOKEN_RCURLY", "TOKEN_PLUS",
  "TOKEN_MINUS", "TOKEN_EXPONENT", "TOKEN_STAR", "TOKEN_SLASH",
  "TOKEN_MOD", "TOKEN_LT", "TOKEN_GT", "TOKEN_GE", "TOKEN_LE", "TOKEN_EQ",
  "TOKEN_NE", "TOKEN_AND", "TOKEN_OR", "TOKEN_COLON", "TOKEN_SEMICOLON",
  "TOKEN_COMMA", "TOKEN_INT_LITERAL", "TOKEN_CHAR_LITERAL", "TOKEN_ASSIGN",
  "TOKEN_COMMENT", "TOKEN_STRING_LITERAL", "TOKEN_DECREMENT",
  "TOKEN_IDENTIFIER", "TOKEN_INCREMENT", "TOKEN_NEGATION",
  "TOKEN_LENGTH_ERROR", "TOKEN_ERROR", "$accept", "program", "decl_list",
  "decl", "assign_decl", "type", "expr", "expr2", "expr3", "expr4",
  "expr5", "expr6", "expr7", "expr8", "expr9", "expr10", "expr11",
  "opt_expr", "stmt", "stmt2", "stmt3", "stmt4", "stmt_list", "param_list",
  "bracket_list", "expr_list", "expr_list2", "ident", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -42,  -150,    53,  -150,   -42,  -150,    22,  -150,  -150,   118,
      46,  -150,  -150,   171,  -150,  -150,  -150,    10,    14,    56,
    -150,    14,  -150,  -150,    14,    14,    23,  -150,  -150,  -150,
      23,    38,    80,    88,   168,   106,   110,    99,  -150,    67,
    -150,   107,   100,   -42,    19,   -10,    36,    67,    67,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,  -150,  -150,   171,    14,    14,  -150,
      27,    95,  -150,  -150,    14,   117,    80,    88,   168,   106,
     106,   106,   106,   106,   106,   110,   110,    99,    99,    99,
    -150,  -150,    36,   128,     1,    43,   -42,   171,    36,  -150,
    -150,  -150,   133,  -150,   132,   124,  -150,  -150,    14,  -150,
      65,   171,     4,   147,   150,    14,    14,    65,  -150,    45,
      65,  -150,  -150,   146,    51,  -150,   133,    14,    14,   138,
     139,    62,   149,  -150,  -150,  -150,  -150,   140,    -6,  -150,
    -150,  -150,    14,   148,   141,   163,   165,  -150,   178,   180,
      14,    14,    14,    65,   152,   155,    -3,  -150,    65,    14,
     148,  -150,   157,   182,    14,   148,   172,  -150,   148,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    81,     0,     2,     4,     7,     0,     1,     3,     0,
       0,    11,    12,     0,    10,    13,    14,     0,    56,     0,
       5,     0,    50,    49,     0,     0,     0,    46,    47,    48,
       0,    55,    17,    19,    21,    28,    31,    35,    37,    40,
      43,     0,    45,    74,     0,     0,    80,    39,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    41,     0,    78,     0,    44,
       0,     0,     9,    52,     0,     0,    16,    18,    20,    22,
      23,    24,    25,    26,    27,    29,    30,    32,    33,    34,
      36,    15,    80,     0,     0,     0,     0,     0,    80,    51,
      77,    54,    76,     6,     0,     0,    72,    79,     0,    53,
      71,     0,     0,     0,     0,    78,    56,    71,    60,     0,
      71,    57,    58,     0,    45,    73,    76,    56,     0,     0,
       0,    80,     0,    64,    70,     8,    75,     0,     0,    66,
      65,    63,    56,     0,     0,     0,     0,    61,    58,     0,
      56,    56,     0,     0,     0,     0,     0,    62,     0,    56,
       0,    59,     0,     0,    56,     0,     0,    67,     0,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   189,    93,  -150,   -11,   -16,   162,   164,   161,
     153,    92,    85,   154,    79,  -150,  -150,  -115,  -140,  -150,
    -136,  -149,   -22,  -150,    87,   101,   -77,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,     5,    17,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    69,    41,   120,   121,
     122,   149,   123,    70,   109,    93,    75,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,   130,    19,   147,     6,    44,     1,   148,    45,    46,
      73,   163,   137,   157,   143,   100,   167,   160,   161,   169,
     147,   107,    22,   102,   148,   157,   126,   144,   161,   148,
      23,    22,   148,    24,    49,   154,   155,    25,    49,    23,
      26,    49,    24,    71,   162,    49,    25,    95,    49,   166,
      20,    92,    94,     7,    21,    91,    27,    28,    98,    72,
      29,     9,     1,    49,    30,    27,    28,    18,    96,    29,
      67,     1,    68,    22,   113,    43,   114,    74,   115,   116,
      49,    23,    49,   103,    24,   133,   106,   104,   117,    49,
       9,    26,   112,     4,   119,   132,   105,     4,   134,    92,
     125,   131,   133,    74,   119,    47,    49,    27,    28,    48,
     124,    29,   138,     1,    64,    30,    65,   124,    50,    67,
     124,    68,    10,    11,    12,    51,    63,   119,    13,    66,
      14,    58,    59,    15,    97,    16,   156,   119,    60,    61,
      62,    99,   119,   124,   119,    87,    88,    89,   101,   119,
      85,    86,   119,   124,   108,   110,    22,   145,   124,   146,
     124,   115,   116,   111,    23,   124,   127,    24,   124,   128,
     135,   117,   158,   141,    26,    10,    11,    12,   139,   140,
     142,   150,   151,    14,   152,   -69,    15,   153,    16,   165,
      27,    28,   168,     8,    29,   159,     1,   164,    30,    52,
      53,    54,    55,    56,    57,    79,    80,    81,    82,    83,
      84,    76,    78,   136,    77,     0,   129,    90
};

static const yytype_int16 yycheck[] =
{
       0,   116,    13,   143,     4,    21,    48,   143,    24,    25,
      20,   160,   127,   153,    20,    92,   165,    20,   158,   168,
     160,    98,     8,    22,   160,   165,    22,   142,   168,   165,
      16,     8,   168,    19,    44,   150,   151,    23,    44,    16,
      26,    44,    19,    43,   159,    44,    23,    20,    44,   164,
      40,    67,    68,     0,    44,    66,    42,    43,    74,    40,
      46,    39,    48,    44,    50,    42,    43,    21,    41,    46,
      19,    48,    21,     8,     9,    19,    11,    41,    13,    14,
      44,    16,    44,    40,    19,    40,    97,    44,    23,    44,
      39,    26,   108,     0,   110,   117,    96,     4,   120,   115,
     111,   117,    40,    41,   120,    26,    44,    42,    43,    30,
     110,    46,   128,    48,    47,    50,    49,   117,    38,    19,
     120,    21,     4,     5,     6,    37,    27,   143,    10,    22,
      12,    25,    26,    15,    39,    17,   152,   153,    28,    29,
      30,    24,   158,   143,   160,    60,    61,    62,    20,   165,
      58,    59,   168,   153,    21,    23,     8,     9,   158,    11,
     160,    13,    14,    39,    16,   165,    19,    19,   168,    19,
      24,    23,    20,    24,    26,     4,     5,     6,    40,    40,
      40,    40,    19,    12,    19,     7,    15,     7,    17,     7,
      42,    43,    20,     4,    46,    40,    48,    40,    50,    31,
      32,    33,    34,    35,    36,    52,    53,    54,    55,    56,
      57,    49,    51,   126,    50,    -1,   115,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    54,    55,    56,    57,    80,     0,    55,    39,
       4,     5,     6,    10,    12,    15,    17,    58,    21,    58,
      40,    44,     8,    16,    19,    23,    26,    42,    43,    46,
      50,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    70,    80,    19,    59,    59,    59,    67,    67,    44,
      38,    37,    31,    32,    33,    34,    35,    36,    25,    26,
      28,    29,    30,    27,    47,    49,    22,    19,    21,    69,
      76,    80,    40,    20,    41,    79,    60,    61,    62,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      66,    58,    59,    78,    59,    20,    41,    39,    59,    24,
      79,    20,    22,    40,    44,    80,    58,    79,    21,    77,
      23,    39,    59,     9,    11,    13,    14,    23,    56,    59,
      71,    72,    73,    75,    80,    58,    22,    19,    19,    78,
      70,    59,    75,    40,    75,    24,    77,    70,    59,    40,
      40,    24,    40,    20,    70,     9,    11,    71,    73,    74,
      40,    19,    19,     7,    70,    70,    59,    71,    20,    40,
      20,    71,    70,    74,    40,     7,    70,    74,    20,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     8,     1,    11,     6,
       1,     1,     1,     1,     1,     5,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     1,     2,     2,
       1,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     4,     3,     4,     3,     1,     0,     1,     1,     9,
       1,     5,     7,     3,     2,     3,     3,     7,     9,     1,
       2,     0,     3,     5,     0,     4,     0,     2,     0,     3,
       0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 88 "parser.bison" /* yacc.c:1646  */
    { parser_result = (yyvsp[0].decl); }
#line 1410 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].decl)->next = (yyvsp[0].decl); (yyval.decl) = (yyvsp[-1].decl); }
#line 1416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = 0; }
#line 1422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-3].name), (yyvsp[-1].type), 0, 0, 0); }
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-7].name), type_create(TYPE_FUNCTION, (yyvsp[-2].param_list), (yyvsp[-4].type), 0), 0, 0, 0); }
#line 1434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-10].name), type_create(TYPE_FUNCTION, (yyvsp[-5].param_list), (yyvsp[-7].type), 0), 0, (yyvsp[-1].stmt), 0); }
#line 1446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].name), (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0); }
#line 1452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); }
#line 1458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); }
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 116 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); }
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, 0, 0, 0); }
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); }
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, 0, (yyvsp[0].type), (yyvsp[-2].expr)); }
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr), 0); }
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr), 1); }
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr), 2); }
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 144 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr), 3); }
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr), 3); }
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr), 3); }
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr), 3); }
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr), 3); }
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NE, (yyvsp[-2].expr), (yyvsp[0].expr), 3); }
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 156 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 160 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr), 4); }
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr), 4); }
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 164 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 168 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr), 5); }
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 170 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr), 5); }
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 172 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr), 5); }
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 174 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 178 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXPONENT, (yyvsp[-2].expr), (yyvsp[0].expr), 6); }
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 184 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEGATION, (yyvsp[0].expr), 0, 7); }
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEGATIVE, (yyvsp[0].expr), 0, 8); }
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 188 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 192 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_INCREMENT, (yyvsp[-1].expr), 0, 9); }
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 194 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DECREMENT, (yyvsp[-1].expr), 0, 9); }
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 196 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 200 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[0].expr)->left = expr_create_name((yyvsp[-1].name)); (yyval.expr) = (yyvsp[0].expr); }
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 202 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_name((yyvsp[0].name)); }
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 204 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); }
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 206 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_character_literal(yytext[0]); }
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 208 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_string_literal(strdup(yytext)); }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 210 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(0); }
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 212 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal(1); }
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 214 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARRAY_INIT, 0, expr_create(EXPR_ARG, (yyvsp[-2].expr), (yyvsp[-1].expr), 10), 10); }
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 216 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 220 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUBSCRIPT, 0, expr_create(EXPR_BRACKET_LIST, (yyvsp[-2].expr), (yyvsp[0].expr), 10), 10); }
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 222 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_FCALL, 0, (yyvsp[-1].expr), 10); }
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 226 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 228 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 232 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 234 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 236 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 238 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0); }
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 242 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0); }
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 244 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 248 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0); }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 250 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 252 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 254 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[-1].expr), 0, 0, 0); }
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 258 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 260 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0); }
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 262 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 266 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt);}
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 268 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = 0; }
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 272 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-2].name), (yyvsp[0].type), 0); }
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 274 "parser.bison" /* yacc.c:1646  */
    { (yyvsp[-4].param_list)->next = param_list_create((yyvsp[-2].name), (yyvsp[0].type), 0); (yyval.param_list) = (yyvsp[-4].param_list); }
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 276 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = 0; }
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 280 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_BRACKET_LIST, (yyvsp[-2].expr), (yyvsp[0].expr), 10); }
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 282 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1854 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 286 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr), 10); }
#line 1860 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 288 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 292 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr), 10); }
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 294 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = 0; }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 298 "parser.bison" /* yacc.c:1646  */
    { (yyval.name) = strdup(yytext); }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1888 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 301 "parser.bison" /* yacc.c:1906  */


int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 0;
}
