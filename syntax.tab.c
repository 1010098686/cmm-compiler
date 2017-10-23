/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     ID = 260,
     SEMI = 261,
     COMMA = 262,
     TYPE = 263,
     LC = 264,
     RC = 265,
     LP = 266,
     RP = 267,
     LB = 268,
     RB = 269,
     STRUCT = 270,
     RETURN = 271,
     IF = 272,
     ELSE = 273,
     WHILE = 274,
     DOT = 275,
     ASSIGNOP = 276,
     AND = 277,
     OR = 278,
     NOT = 279,
     PLUS = 280,
     MINUS = 281,
     STAR = 282,
     DIV = 283,
     RELOP = 284,
     LOWER_THAN_ELSE = 285
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define ID 260
#define SEMI 261
#define COMMA 262
#define TYPE 263
#define LC 264
#define RC 265
#define LP 266
#define RP 267
#define LB 268
#define RB 269
#define STRUCT 270
#define RETURN 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define DOT 275
#define ASSIGNOP 276
#define AND 277
#define OR 278
#define NOT 279
#define PLUS 280
#define MINUS 281
#define STAR 282
#define DIV 283
#define RELOP 284
#define LOWER_THAN_ELSE 285




/* Copy the first part of user declarations.  */
#line 1 "syntax.y"

#define YYDEBUG 1
#include"lex.yy.c"
#include "tree.h"
extern void yyerror(char* msg);


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 8 "syntax.y"
{
    struct tree_node *type_node;
}
/* Line 193 of yacc.c.  */
#line 167 "syntax.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "syntax.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   228

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    16,    20,    22,
      26,    28,    30,    36,    39,    41,    42,    44,    46,    51,
      56,    60,    64,    66,    69,    74,    77,    78,    81,    83,
      87,    93,   101,   107,   110,   111,   115,   117,   121,   123,
     127,   131,   135,   139,   143,   147,   151,   155,   159,   163,
     166,   169,   174,   178,   183,   187,   189,   191,   193,   197
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    -1,    34,    33,    -1,    -1,    36,
      35,     6,    -1,    36,     6,    -1,    36,    41,    44,    -1,
      40,    -1,    40,     7,    35,    -1,     8,    -1,    37,    -1,
      15,    38,     9,    47,    10,    -1,    15,    39,    -1,     5,
      -1,    -1,     5,    -1,     5,    -1,    40,    13,     3,    14,
      -1,     5,    11,    42,    12,    -1,     5,    11,    12,    -1,
      43,     7,    42,    -1,    43,    -1,    36,    40,    -1,     9,
      47,    45,    10,    -1,    46,    45,    -1,    -1,    51,     6,
      -1,    44,    -1,    16,    51,     6,    -1,    17,    11,    51,
      12,    46,    -1,    17,    11,    51,    12,    46,    18,    46,
      -1,    19,    11,    51,    12,    46,    -1,    48,    47,    -1,
      -1,    36,    49,     6,    -1,    50,    -1,    50,     7,    49,
      -1,    40,    -1,    40,    21,    51,    -1,    51,    21,    51,
      -1,    51,    22,    51,    -1,    51,    23,    51,    -1,    51,
      29,    51,    -1,    51,    25,    51,    -1,    51,    26,    51,
      -1,    51,    27,    51,    -1,    51,    28,    51,    -1,    11,
      51,    12,    -1,    26,    51,    -1,    24,    51,    -1,     5,
      11,    52,    12,    -1,     5,    11,    12,    -1,    51,    13,
      51,    14,    -1,    51,    20,     5,    -1,     5,    -1,     3,
      -1,     4,    -1,    51,     7,    52,    -1,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    45,    46,    48,    49,    50,    52,    53,
      55,    56,    58,    59,    61,    62,    64,    65,    66,    68,
      69,    71,    72,    74,    75,    76,    77,    79,    80,    81,
      82,    83,    84,    86,    87,    89,    90,    91,    93,    94,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   115,   116
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "SEMI", "COMMA",
  "TYPE", "LC", "RC", "LP", "RP", "LB", "RB", "STRUCT", "RETURN", "IF",
  "ELSE", "WHILE", "DOT", "ASSIGNOP", "AND", "OR", "NOT", "PLUS", "MINUS",
  "STAR", "DIV", "RELOP", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", 0
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
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    35,    35,
      36,    36,    37,    37,    38,    38,    39,    40,    40,    41,
      41,    42,    42,    43,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     2,     1,     0,     1,     1,     4,     4,
       3,     3,     1,     2,     4,     2,     0,     2,     1,     3,
       5,     7,     5,     2,     0,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     4,     3,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    15,     0,     2,     4,     0,    11,    16,     0,
      13,     1,     3,    17,     6,     0,     8,     0,    34,     0,
       5,     0,     0,    34,     7,     0,     0,    34,    20,     0,
       0,    22,    17,     9,     0,    26,    38,     0,    36,    12,
      33,    23,    19,     0,    18,    56,    57,    55,     0,     0,
       0,     0,     0,     0,    28,     0,    26,     0,     0,    35,
       0,    21,     0,     0,     0,     0,     0,    50,    49,    24,
      25,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    37,    52,    59,     0,    48,    29,     0,
       0,     0,    54,    40,    41,    42,    44,    45,    46,    47,
      43,     0,    51,     0,     0,    53,    58,    30,    32,     0,
      31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    25,     7,     9,    10,    16,
      17,    30,    31,    54,    55,    56,    26,    27,    37,    38,
      57,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
       7,   -85,    18,     6,   -85,     7,    58,   -85,    27,    37,
     -85,   -85,   -85,    57,   -85,    59,    54,    63,     7,     1,
     -85,    81,    84,     7,   -85,    81,    83,     7,   -85,    81,
      86,    94,   -85,   -85,    91,    80,   -10,   113,   104,   -85,
     -85,   107,   -85,     7,   -85,   -85,   -85,   110,    66,    66,
     111,   112,    66,    66,   -85,   114,    80,    29,    66,   -85,
      81,   -85,    36,   105,    53,    66,    66,    24,    75,   -85,
     -85,   -85,    66,   124,    66,    66,    66,    66,    66,    66,
      66,    66,   169,   -85,   -85,    87,   125,   -85,   -85,   123,
     141,   158,   -85,   169,   190,   180,    75,    75,    24,    24,
     200,    66,   -85,    80,    80,   -85,   -85,   120,   -85,    80,
     -85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   134,   -85,   119,     2,   -85,   -85,   -85,   -17,
     -85,    98,   -85,   130,    99,   -84,    11,   -85,    82,   -85,
     -48,    55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      63,    64,     6,    22,    67,    68,    11,     6,    36,     1,
      82,    58,    41,    28,    85,     1,     2,    89,    90,   107,
     108,    29,     2,     8,    91,   110,    93,    94,    95,    96,
      97,    98,    99,   100,    35,    71,   -14,    72,    40,    45,
      46,    47,    72,    36,    73,    29,    18,    48,    84,    73,
      74,    75,    76,    85,    77,    78,    79,    80,    81,    88,
      52,    21,    53,    13,    14,    20,    72,    22,    19,    45,
      46,    47,    23,    73,    74,    75,    76,    48,    77,    78,
      79,    80,    81,    45,    46,    47,    32,    34,    72,    23,
      52,    48,    53,    39,   101,    73,    49,    50,    42,    51,
      72,    43,    79,    80,    52,    44,    53,    73,    74,    75,
      76,    60,    77,    78,    79,    80,    81,    87,    72,    59,
      22,    62,    65,    66,    69,    73,    74,    75,    76,    92,
      77,    78,    79,    80,    81,   103,    72,   102,   109,    12,
      33,    61,    83,    73,    74,    75,    76,    24,    77,    78,
      79,    80,    81,   104,    72,    70,   106,     0,     0,     0,
       0,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    72,   105,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    72,    77,    78,    79,    80,    81,     0,    73,
      74,    75,    76,    72,    77,    78,    79,    80,    81,     0,
      73,     0,    75,    72,     0,    77,    78,    79,    80,    81,
      73,     0,     0,    72,     0,    77,    78,    79,    80,    81,
      73,     0,     0,     0,     0,    77,    78,    79,    80
};

static const yytype_int8 yycheck[] =
{
      48,    49,     0,    13,    52,    53,     0,     5,    25,     8,
      58,    21,    29,    12,    62,     8,    15,    65,    66,   103,
     104,    19,    15,     5,    72,   109,    74,    75,    76,    77,
      78,    79,    80,    81,    23,     6,     9,    13,    27,     3,
       4,     5,    13,    60,    20,    43,     9,    11,    12,    20,
      21,    22,    23,   101,    25,    26,    27,    28,    29,     6,
      24,     7,    26,     5,     6,     6,    13,    13,    11,     3,
       4,     5,     9,    20,    21,    22,    23,    11,    25,    26,
      27,    28,    29,     3,     4,     5,     5,     3,    13,     9,
      24,    11,    26,    10,     7,    20,    16,    17,    12,    19,
      13,     7,    27,    28,    24,    14,    26,    20,    21,    22,
      23,     7,    25,    26,    27,    28,    29,    12,    13,     6,
      13,    11,    11,    11,    10,    20,    21,    22,    23,     5,
      25,    26,    27,    28,    29,    12,    13,    12,    18,     5,
      21,    43,    60,    20,    21,    22,    23,    17,    25,    26,
      27,    28,    29,    12,    13,    56,   101,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    13,    25,    26,    27,    28,    29,    -1,    20,
      21,    22,    23,    13,    25,    26,    27,    28,    29,    -1,
      20,    -1,    22,    13,    -1,    25,    26,    27,    28,    29,
      20,    -1,    -1,    13,    -1,    25,    26,    27,    28,    29,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    15,    32,    33,    34,    36,    37,     5,    38,
      39,     0,    33,     5,     6,    35,    40,    41,     9,    11,
       6,     7,    13,     9,    44,    36,    47,    48,    12,    36,
      42,    43,     5,    35,     3,    47,    40,    49,    50,    10,
      47,    40,    12,     7,    14,     3,     4,     5,    11,    16,
      17,    19,    24,    26,    44,    45,    46,    51,    21,     6,
       7,    42,    11,    51,    51,    11,    11,    51,    51,    10,
      45,     6,    13,    20,    21,    22,    23,    25,    26,    27,
      28,    29,    51,    49,    12,    51,    52,    12,     6,    51,
      51,    51,     5,    51,    51,    51,    51,    51,    51,    51,
      51,     7,    12,    12,    12,    14,    52,    46,    46,    18,
      46
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 44 "syntax.y"
    {(yyval.type_node) = new_tree_node(PROGRAM_T, (yyloc).first_line, NULL);root = (yyval.type_node);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 3:
#line 45 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXTDEFLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 4:
#line 46 "syntax.y"
    {(yyval.type_node) = NULL;;}
    break;

  case 5:
#line 48 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXTDEF_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 6:
#line 49 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXTDEF_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 7:
#line 50 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXTDEF_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 8:
#line 52 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXTDECLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 9:
#line 53 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXTDECLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 10:
#line 55 "syntax.y"
    {(yyval.type_node) = new_tree_node(SPECIFIER_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 11:
#line 56 "syntax.y"
    {(yyval.type_node) = new_tree_node(SPECIFIER_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 12:
#line 58 "syntax.y"
    {(yyval.type_node) = new_tree_node(STRUCTSPECIFIER_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 5, (yyvsp[(1) - (5)].type_node), (yyvsp[(2) - (5)].type_node), (yyvsp[(3) - (5)].type_node), (yyvsp[(4) - (5)].type_node), (yyvsp[(5) - (5)].type_node));;}
    break;

  case 13:
#line 59 "syntax.y"
    {(yyval.type_node) = new_tree_node(STRUCTSPECIFIER_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 14:
#line 61 "syntax.y"
    {(yyval.type_node) = new_tree_node(OPTTAG_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 15:
#line 62 "syntax.y"
    {(yyval.type_node) = NULL;;}
    break;

  case 16:
#line 64 "syntax.y"
    {(yyval.type_node) = new_tree_node(TAG_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 17:
#line 65 "syntax.y"
    {(yyval.type_node) = new_tree_node(VARDEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 18:
#line 66 "syntax.y"
    {(yyval.type_node) = new_tree_node(VARDEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 4, (yyvsp[(1) - (4)].type_node), (yyvsp[(2) - (4)].type_node), (yyvsp[(3) - (4)].type_node), (yyvsp[(4) - (4)].type_node));;}
    break;

  case 19:
#line 68 "syntax.y"
    {(yyval.type_node) = new_tree_node(FUNDEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 4, (yyvsp[(1) - (4)].type_node), (yyvsp[(2) - (4)].type_node), (yyvsp[(3) - (4)].type_node), (yyvsp[(4) - (4)].type_node));;}
    break;

  case 20:
#line 69 "syntax.y"
    {(yyval.type_node) = new_tree_node(FUNDEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 21:
#line 71 "syntax.y"
    {(yyval.type_node) = new_tree_node(VARLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 22:
#line 72 "syntax.y"
    {(yyval.type_node) = new_tree_node(VARLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 23:
#line 74 "syntax.y"
    {(yyval.type_node) = new_tree_node(PARAMDEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 24:
#line 75 "syntax.y"
    {(yyval.type_node) = new_tree_node(COMPST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 4, (yyvsp[(1) - (4)].type_node), (yyvsp[(2) - (4)].type_node), (yyvsp[(3) - (4)].type_node), (yyvsp[(4) - (4)].type_node));;}
    break;

  case 25:
#line 76 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMTLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 26:
#line 77 "syntax.y"
    {(yyval.type_node) = NULL;;}
    break;

  case 27:
#line 79 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMT_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 28:
#line 80 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMT_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 29:
#line 81 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMT_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 30:
#line 82 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMT_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 5, (yyvsp[(1) - (5)].type_node), (yyvsp[(2) - (5)].type_node), (yyvsp[(3) - (5)].type_node), (yyvsp[(4) - (5)].type_node), (yyvsp[(5) - (5)].type_node));;}
    break;

  case 31:
#line 83 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMT_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 7, (yyvsp[(1) - (7)].type_node), (yyvsp[(2) - (7)].type_node), (yyvsp[(3) - (7)].type_node), (yyvsp[(4) - (7)].type_node), (yyvsp[(5) - (7)].type_node), (yyvsp[(6) - (7)].type_node), (yyvsp[(7) - (7)].type_node));;}
    break;

  case 32:
#line 84 "syntax.y"
    {(yyval.type_node) = new_tree_node(STMT_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 5, (yyvsp[(1) - (5)].type_node), (yyvsp[(2) - (5)].type_node), (yyvsp[(3) - (5)].type_node), (yyvsp[(4) - (5)].type_node), (yyvsp[(5) - (5)].type_node));;}
    break;

  case 33:
#line 86 "syntax.y"
    {(yyval.type_node) = new_tree_node(DEFLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 34:
#line 87 "syntax.y"
    {(yyval.type_node) = NULL;;}
    break;

  case 35:
#line 89 "syntax.y"
    {(yyval.type_node) = new_tree_node(DEF_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 36:
#line 90 "syntax.y"
    {(yyval.type_node) = new_tree_node(DECLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 37:
#line 91 "syntax.y"
    {(yyval.type_node) = new_tree_node(DECLIST_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 38:
#line 93 "syntax.y"
    {(yyval.type_node) = new_tree_node(DEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 39:
#line 94 "syntax.y"
    {(yyval.type_node) = new_tree_node(DEC_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 40:
#line 96 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 41:
#line 97 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 42:
#line 98 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 43:
#line 99 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 44:
#line 100 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 45:
#line 101 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 46:
#line 102 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 47:
#line 103 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 48:
#line 104 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 49:
#line 105 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 50:
#line 106 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 2, (yyvsp[(1) - (2)].type_node), (yyvsp[(2) - (2)].type_node));;}
    break;

  case 51:
#line 107 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 4, (yyvsp[(1) - (4)].type_node), (yyvsp[(2) - (4)].type_node), (yyvsp[(3) - (4)].type_node), (yyvsp[(4) - (4)].type_node));;}
    break;

  case 52:
#line 108 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 53:
#line 109 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 4, (yyvsp[(1) - (4)].type_node), (yyvsp[(2) - (4)].type_node), (yyvsp[(3) - (4)].type_node), (yyvsp[(4) - (4)].type_node));;}
    break;

  case 54:
#line 110 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 55:
#line 111 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 56:
#line 112 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 57:
#line 113 "syntax.y"
    {(yyval.type_node) = new_tree_node(EXP_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;

  case 58:
#line 115 "syntax.y"
    {(yyval.type_node) = new_tree_node(ARGS_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 3, (yyvsp[(1) - (3)].type_node), (yyvsp[(2) - (3)].type_node), (yyvsp[(3) - (3)].type_node));;}
    break;

  case 59:
#line 116 "syntax.y"
    {(yyval.type_node) = new_tree_node(ARGS_T, (yyloc).first_line, NULL);add_children((yyval.type_node), 1, (yyvsp[(1) - (1)].type_node));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1816 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 118 "syntax.y"

void yyerror(char* msg){
	fprintf(stderr,"Error type B at Line %d: %s\n", yylineno, msg);
    error = 1;
}

