%option noyywrap
/* 
 * Analisador léxico da linguagem Simple++ 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex lex.l
 *        (2) $ gcc lex.yy.c 
 *        (3) $ ./a.out < mergeSort.txt
 */

%{
#include <stdio.h>  
#include <string.h>
#include "parser.tab.h"
%}

%option yylineno

%%

[ \t\n]               ;
[0-9]+                {yylval.iValue = atoi(yytext); return INT_NUMBER;}
((\+|-)?([0-9]+)(\.[0-9]+)?)|((\+|-)?\.?[0-9]+) {yylval.dValue = strtod(yytext, NULL); return DOUBLE_NUMBER; }
"int"                { return INT; }
"double"                { return DOUBLE; }
"bool"                { return BOOL; }
"float"                { return FLOAT; }
"string"                { return STRING; }
"enum"                { return ENUM; }
"pointer"                { return POINTER; }
"pointTo"              {return POINT_TO;}

"main"                     { return MAIN; }
"procedure"                { return PROCEDURE; }
"function"                { return FUNCTION; }
"return"                { return RETURN; }
"while"               { return WHILE; }
"do"                  { return DO; }
"if"                  { return IF; }
"else"                { return ELSE; }
"for"                { return FOR; }
"switch"                { return SWITCH; }
"case"                { return CASE; }
"break"                { return BREAK; }
"default"                { return DEFAULT; }
"print"                { return PRINT; }
"scan"                { return SCAN; }
([\"].*?[\"])  {yylval.sValue = strdup(yytext); return STRING_LITERAL; }   

"printArray"       { return PRINT_ARRAY; }

"true"             { return TRUE; }
"false"            { return FALSE; }
","                { return COMMA; }
":"                { return COLON; }
";"                { return SEMI_COLON; }
"("                { return LPAREN; }
")"                { return RPAREN; }
"["                { return LBRACK; }
"]"                { return RBRACK; }
"{"                { return LBRACE; }
"}"                { return RBRACE; }
"."                { return DOT; }

"++"               { return INCREMENT; }
"--"               { return DECREMENT; }
"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return MULT; }
"/"                { return DIVIDE; }
"%"                { return MODULE; }
"+="               { return ADD_ASSIGN; }
"-="               { return SUB_ASSIGN; }
"*="               { return MULT_ASSIGN; }
"/="               { return DIVIDE_ASSIGN; }
"%="               { return MODULE_ASSIGN; }
"="                { return ASSIGN; }

"=="               { return EQ; }
"!="               { return NEQ; }
"<"                { return LT; }
"<="               { return LE; }
">"                { return GT; }
">="               { return GE; }

"&"                { return AND; }
"|"                { return OR; }
"!"                { return NOT; }


[a-zA-Z][a-zA-Z0-9_]*               {yylval.sValue = strdup(yytext); return ID;}

.               {printf ("Invalid character.");}

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif

