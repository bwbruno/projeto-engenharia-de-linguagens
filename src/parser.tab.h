
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
     ID = 258,
     STRING_LITERAL = 259,
     INT_NUMBER = 260,
     DOUBLE_NUMBER = 261,
     INT = 262,
     DOUBLE = 263,
     STRING = 264,
     BOOL = 265,
     ENUM = 266,
     POINTER = 267,
     PROCEDURE = 268,
     FUNCTION = 269,
     RETURN = 270,
     WHILE = 271,
     DO = 272,
     IF = 273,
     ELSE = 274,
     FOR = 275,
     SWITCH = 276,
     CASE = 277,
     BREAK = 278,
     DEFAULT = 279,
     PRINT = 280,
     SCAN = 281,
     PRINT_ARRAY = 282,
     TRUE = 283,
     FALSE = 284,
     COMMA = 285,
     COLON = 286,
     SEMI_COLON = 287,
     LPAREN = 288,
     RPAREN = 289,
     LBRACK = 290,
     RBRACK = 291,
     LBRACE = 292,
     RBRACE = 293,
     DOT = 294,
     INCREMENT = 295,
     DECREMENT = 296,
     PLUS = 297,
     MINUS = 298,
     MULT = 299,
     DIVIDE = 300,
     MODULE = 301,
     ADD_ASSIGN = 302,
     SUB_ASSIGN = 303,
     MULT_ASSIGN = 304,
     DIVIDE_ASSIGN = 305,
     MODULE_ASSIGN = 306,
     ASSIGN = 307,
     EQ = 308,
     NEQ = 309,
     LT = 310,
     LE = 311,
     GT = 312,
     GE = 313,
     AND = 314,
     OR = 315,
     NOT = 316
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "parser.y"

	int    iValue; 	/* integer value */
    float  dValue;   /* double value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */



/* Line 1676 of yacc.c  */
#line 122 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


