
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 9 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;



/* Line 189 of yacc.c  */
#line 86 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING_LITERAL = 259,
     INT_NUMBER = 260,
     DOUBLE_NUMBER = 261,
     INT = 262,
     FLOAT = 263,
     DOUBLE = 264,
     STRING = 265,
     BOOL = 266,
     ENUM = 267,
     POINTER = 268,
     MAIN = 269,
     PROCEDURE = 270,
     FUNCTION = 271,
     RETURN = 272,
     WHILE = 273,
     DO = 274,
     IF = 275,
     ELSE = 276,
     FOR = 277,
     SWITCH = 278,
     CASE = 279,
     BREAK = 280,
     DEFAULT = 281,
     PRINT = 282,
     SCAN = 283,
     PRINT_ARRAY = 284,
     TRUE = 285,
     FALSE = 286,
     COMMA = 287,
     COLON = 288,
     SEMI_COLON = 289,
     LPAREN = 290,
     RPAREN = 291,
     LBRACK = 292,
     RBRACK = 293,
     LBRACE = 294,
     RBRACE = 295,
     DOT = 296,
     INCREMENT = 297,
     DECREMENT = 298,
     PLUS = 299,
     MINUS = 300,
     MULT = 301,
     DIVIDE = 302,
     MODULE = 303,
     ADD_ASSIGN = 304,
     SUB_ASSIGN = 305,
     MULT_ASSIGN = 306,
     DIVIDE_ASSIGN = 307,
     MODULE_ASSIGN = 308,
     ASSIGN = 309,
     EQ = 310,
     NEQ = 311,
     LT = 312,
     LE = 313,
     GT = 314,
     GE = 315,
     AND = 316,
     OR = 317,
     NOT = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 "parser.y"

	int    iValue; 	/* integer value */
    float  dValue;   /* double value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */



/* Line 214 of yacc.c  */
#line 194 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    11,    15,    18,    22,    23,
      27,    31,    33,    39,    41,    44,    46,    48,    57,    68,
      79,    81,    82,    86,    88,    92,    94,    96,    98,   100,
     102,   104,   107,   109,   111,   113,   115,   118,   122,   127,
     129,   131,   133,   135,   137,   139,   141,   143,   145,   147,
     149,   151,   155,   159,   163,   167,   171,   179,   189,   197,
     205,   213,   216,   219,   222,   225,   229,   231,   233,   235,
     237,   239,   243,   245,   247,   249,   251,   253,   255,   257,
     259,   261
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    70,    -1,    67,    34,    66,    -1,
      -1,    77,    68,    69,    -1,    37,    38,    -1,    68,    37,
      38,    -1,    -1,    69,    32,     3,    -1,     3,    81,    82,
      -1,     3,    -1,    69,    32,     3,    81,    82,    -1,    71,
      -1,    70,    71,    -1,    72,    -1,    73,    -1,    15,     3,
      35,    74,    36,    39,    78,    40,    -1,    16,     3,    35,
      74,    36,    33,    77,    39,    78,    40,    -1,    16,    14,
      35,    74,    36,    33,    77,    39,    78,    40,    -1,    75,
      -1,    -1,    75,    32,    76,    -1,    76,    -1,    77,    68,
       3,    -1,     7,    -1,     9,    -1,     8,    -1,    10,    -1,
      11,    -1,    79,    -1,    78,    79,    -1,    83,    -1,    84,
      -1,    66,    -1,    85,    -1,    87,    34,    -1,     3,    81,
      82,    -1,    77,     3,    81,    82,    -1,    54,    -1,    49,
      -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,     3,
      -1,     5,    -1,     6,    -1,     4,    -1,    30,    -1,    31,
      -1,    82,    44,    82,    -1,    82,    45,    82,    -1,    82,
      46,    82,    -1,    82,    47,    82,    -1,    82,    48,    82,
      -1,    18,    35,    88,    36,    39,    78,    40,    -1,    19,
      39,    78,    40,    18,    35,    88,    36,    34,    -1,    20,
      35,    88,    36,    39,    78,    40,    -1,    22,    35,    86,
      36,    39,    78,    40,    -1,    80,    34,     3,    92,     3,
      34,    87,    -1,     3,    42,    -1,     3,    43,    -1,    42,
       3,    -1,    43,     3,    -1,    88,    93,    89,    -1,    89,
      -1,     3,    -1,    30,    -1,    31,    -1,    90,    -1,    91,
      92,    91,    -1,    82,    -1,    55,    -1,    56,    -1,    60,
      -1,    58,    -1,    59,    -1,    57,    -1,    61,    -1,    62,
      -1,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    50,    51,    54,    57,    58,    59,    62,
      63,    64,    65,    69,    70,    73,    74,    77,    80,    81,
      84,    85,    88,    89,    92,    95,    96,    97,    98,    99,
     102,   103,   106,   107,   109,   110,   111,   128,   129,   132,
     133,   134,   135,   136,   137,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   153,   154,   157,   160,
     163,   166,   167,   168,   169,   178,   179,   182,   183,   184,
     185,   188,   191,   194,   195,   196,   197,   198,   199,   202,
     203,   204
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING_LITERAL", "INT_NUMBER",
  "DOUBLE_NUMBER", "INT", "FLOAT", "DOUBLE", "STRING", "BOOL", "ENUM",
  "POINTER", "MAIN", "PROCEDURE", "FUNCTION", "RETURN", "WHILE", "DO",
  "IF", "ELSE", "FOR", "SWITCH", "CASE", "BREAK", "DEFAULT", "PRINT",
  "SCAN", "PRINT_ARRAY", "TRUE", "FALSE", "COMMA", "COLON", "SEMI_COLON",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT",
  "INCREMENT", "DECREMENT", "PLUS", "MINUS", "MULT", "DIVIDE", "MODULE",
  "ADD_ASSIGN", "SUB_ASSIGN", "MULT_ASSIGN", "DIVIDE_ASSIGN",
  "MODULE_ASSIGN", "ASSIGN", "EQ", "NEQ", "LT", "LE", "GT", "GE", "AND",
  "OR", "NOT", "$accept", "prog", "decls", "decl", "dimen_op", "ids",
  "subprogrs", "subprog", "procedure", "function", "args_op", "args",
  "arg", "type", "stmt_list", "stmt", "assign_stmt", "assign_op", "expr",
  "while_stmt", "if_stmt", "for_stmt", "for_args", "inc_dec", "condition",
  "c_term", "comp", "comp_term", "comp_op", "logic_op", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    68,    68,    68,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    76,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      86,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      89,    90,    91,    92,    92,    92,    92,    92,    92,    93,
      93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     0,     3,     2,     3,     0,     3,
       3,     1,     5,     1,     2,     1,     1,     8,    10,    10,
       1,     0,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     2,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     7,     9,     7,     7,
       7,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    25,    27,    26,    28,    29,     0,     0,     0,     8,
       1,     0,     0,     2,    13,    15,    16,     4,     0,     0,
       0,     0,     0,    14,     3,     6,    11,     0,     5,    21,
      21,    21,    40,    41,    42,    43,    44,    39,     0,     7,
       0,     0,    20,    23,     8,     0,     0,    45,    48,    46,
      47,    49,    50,    10,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,    22,    24,     0,
       0,    51,    52,    53,    54,    55,    12,     0,     0,     0,
       0,     0,     0,     0,    34,     0,    30,    32,    33,    35,
       0,     0,     0,    61,    62,     0,     4,     0,     0,    63,
      64,    17,    31,    36,     4,     4,    45,    49,    50,    72,
       0,    66,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,     0,    73,    74,    78,
      76,    77,    75,     0,     0,     0,     0,     0,     0,     0,
      18,    19,     4,    65,    71,     0,     4,    37,     0,     0,
       4,     0,     0,     0,    38,     0,     0,    56,     0,    58,
       0,    59,     0,     0,    57,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    84,     8,    19,    28,    13,    14,    15,    16,
      41,    42,    43,     9,    85,    86,   118,    38,   109,    87,
      88,    89,   119,    90,   110,   111,   112,   113,   133,   126
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
     217,   -92,   -92,   -92,   -92,   -92,    10,     3,   -21,   -22,
     -92,    18,     6,     3,   -92,   -92,   -92,   217,   -10,     8,
       1,    22,    48,   -92,   -92,   -92,   234,    47,    17,   217,
     217,   217,   -92,   -92,   -92,   -92,   -92,   -92,    29,   -92,
      68,    50,    55,   -92,   -22,    52,    56,   -92,   -92,   -92,
     -92,   -92,   -92,   206,   234,    60,   217,    11,    70,    76,
      29,    29,    29,    29,    29,    29,   253,   -92,   -92,   217,
     217,     5,     5,   -92,   -92,   -92,   206,    13,    77,    62,
      83,    90,   117,   132,   -92,    71,   -92,   -92,   -92,   -92,
     102,    99,   105,   -92,   -92,    36,   253,    36,   271,   -92,
     -92,   -92,   -92,   -92,   253,   253,    14,    33,    61,   206,
      66,   -92,   -92,   143,    97,    85,   234,   147,   119,   115,
     123,   149,   116,   -92,   -92,   -92,    36,   -92,   -92,   -92,
     -92,   -92,   -92,    29,   136,   122,    29,   234,   159,   125,
     -92,   -92,   253,   -92,   -92,   135,   253,   206,    29,   143,
     253,   175,    36,   201,   206,   169,   227,   -92,   113,   -92,
     139,   -92,   145,     4,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,    12,   -92,   133,   -92,   -92,   167,   -92,   -92,
      34,   -92,   131,   -26,   -88,   -83,   -92,   -53,   -38,   -92,
     -92,   -92,   -92,    25,   -91,    64,   -92,    63,    32,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -70
static const yytype_int16 yytable[] =
{
      53,    65,   102,    44,    44,    44,   115,    77,   114,    21,
      10,    26,     7,    17,    68,    18,   120,   121,    11,    12,
      22,    20,    71,    72,    73,    74,    75,    76,    25,    24,
      44,   102,    47,    48,    49,    50,    29,   102,   102,   106,
      48,    49,    50,    91,    92,    27,    82,    83,    27,    40,
     -67,    62,    63,    64,   151,    93,    94,    30,   153,    51,
      52,   158,   156,   136,    45,    46,   107,   108,   102,   -68,
     102,    54,   117,   102,    77,   -67,   -67,   -67,     1,     2,
       3,     4,     5,    31,   148,    39,    55,    56,    58,    78,
      79,    80,    59,    81,   -68,   -68,   -68,   -69,   147,    66,
      77,    96,   122,    69,     1,     2,     3,     4,     5,    70,
     154,   101,    95,    82,    83,    78,    79,    80,    97,    81,
      99,   135,   -69,   -69,   -69,    98,    77,   123,   124,   125,
       1,     2,     3,     4,     5,   100,   103,   134,   104,    82,
      83,    78,    79,    80,   105,    81,   123,   124,   125,   162,
     137,   139,    77,   138,   145,   142,     1,     2,     3,     4,
       5,   146,   149,   140,   150,    82,    83,    78,    79,    80,
     152,    81,   160,   163,   123,   124,   125,    57,    77,   164,
      23,   155,     1,     2,     3,     4,     5,    67,   165,   141,
     143,    82,    83,    78,    79,    80,   144,    81,   127,   128,
     129,   130,   131,   132,    77,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     0,   157,     0,    82,    83,    78,
      79,    80,     0,    81,     1,     2,     3,     4,     5,     0,
      77,     0,     0,     0,     1,     2,     3,     4,     5,     0,
       0,   159,     0,    82,    83,    78,    79,    80,     0,    81,
      60,    61,    62,    63,    64,     0,    77,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     0,   161,     0,    82,
      83,    78,    79,    80,   116,    81,     0,     0,     1,     2,
       3,     4,     5,    32,    33,    34,    35,    36,    37,     0,
       0,     0,     0,     0,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
      38,    54,    85,    29,    30,    31,    97,     3,    96,     3,
       0,     3,     0,    34,     3,    37,   104,   105,    15,    16,
      14,     3,    60,    61,    62,    63,    64,    65,    38,    17,
      56,   114,     3,     4,     5,     6,    35,   120,   121,     3,
       4,     5,     6,    69,    70,    37,    42,    43,    37,    32,
      36,    46,    47,    48,   142,    42,    43,    35,   146,    30,
      31,   152,   150,   116,    30,    31,    30,    31,   151,    36,
     153,     3,    98,   156,     3,    61,    62,    63,     7,     8,
       9,    10,    11,    35,   137,    38,    36,    32,    36,    18,
      19,    20,    36,    22,    61,    62,    63,    36,   136,    39,
       3,    39,    36,    33,     7,     8,     9,    10,    11,    33,
     148,    40,    35,    42,    43,    18,    19,    20,    35,    22,
       3,    36,    61,    62,    63,    35,     3,    61,    62,    63,
       7,     8,     9,    10,    11,     3,    34,    40,    39,    42,
      43,    18,    19,    20,    39,    22,    61,    62,    63,    36,
       3,    36,     3,    34,    18,    39,     7,     8,     9,    10,
      11,    39,     3,    40,    39,    42,    43,    18,    19,    20,
      35,    22,     3,    34,    61,    62,    63,    44,     3,    34,
      13,   149,     7,     8,     9,    10,    11,    56,   163,    40,
     126,    42,    43,    18,    19,    20,   133,    22,    55,    56,
      57,    58,    59,    60,     3,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    40,    -1,    42,    43,    18,
      19,    20,    -1,    22,     7,     8,     9,    10,    11,    -1,
       3,    -1,    -1,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    40,    -1,    42,    43,    18,    19,    20,    -1,    22,
      44,    45,    46,    47,    48,    -1,     3,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    40,    -1,    42,
      43,    18,    19,    20,     3,    22,    -1,    -1,     7,     8,
       9,    10,    11,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    65,    66,    67,    77,
       0,    15,    16,    70,    71,    72,    73,    34,    37,    68,
       3,     3,    14,    71,    66,    38,     3,    37,    69,    35,
      35,    35,    49,    50,    51,    52,    53,    54,    81,    38,
      32,    74,    75,    76,    77,    74,    74,     3,     4,     5,
       6,    30,    31,    82,     3,    36,    32,    68,    36,    36,
      44,    45,    46,    47,    48,    81,    39,    76,     3,    33,
      33,    82,    82,    82,    82,    82,    82,     3,    18,    19,
      20,    22,    42,    43,    66,    78,    79,    83,    84,    85,
      87,    77,    77,    42,    43,    35,    39,    35,    35,     3,
       3,    40,    79,    34,    39,    39,     3,    30,    31,    82,
      88,    89,    90,    91,    78,    88,     3,    77,    80,    86,
      78,    78,    36,    61,    62,    63,    93,    55,    56,    57,
      58,    59,    60,    92,    40,    36,    81,     3,    34,    36,
      40,    40,    39,    89,    91,    18,    39,    82,    81,     3,
      39,    78,    35,    78,    82,    92,    78,    40,    88,    40,
       3,    40,    36,    34,    34,    87
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 47 "parser.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 50 "parser.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 54 "parser.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 58 "parser.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 62 "parser.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    {;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 2114 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 206 "parser.y"


int main (void) {
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
