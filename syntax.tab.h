/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 8 "syntax.y"
{
    struct TREE_NODE *type_node;
}
/* Line 1529 of yacc.c.  */
#line 113 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
