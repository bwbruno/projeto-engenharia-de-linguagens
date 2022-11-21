
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

/* Line 1676 of yacc.c  */
#line 21 "parser.y"

	int    iValue; 	/* integer value */
    float  dValue;   /* double value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */



/* Line 1676 of yacc.c  */
#line 124 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


