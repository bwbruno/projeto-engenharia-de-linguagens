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
#include "stack.h"
#include "symboltable.h"
#include "parser.tab.h"
int line = 0;

%}

%option yylineno

%%

[ \t\n]                 ;
[0-9]+                  {
                           yylval.iValue = atoi(yytext);
                           return INT_NUMBER;
                        }

((\+|-)?([0-9]+)(\.[0-9]+)?)|((\+|-)?\.?[0-9]+) {
                           yylval.dValue = strtod(yytext, NULL);
                           return DOUBLE_NUMBER;
                        }

"int"                   { return INT; }
"double"                { return DOUBLE; }
"bool"                  { return BOOL; }
"float"                 { return FLOAT; }
"string"                { return STRING; }
"enum"                  { return ENUM; }
"pointer"               { return POINTER; }
"pointTo"               { return POINT_TO; }
"main"                  { strcpy(yylval.nd_obj.name,(yytext)); return MAIN; }
"procedure"             { strcpy(yylval.nd_obj.name,(yytext)); return PROCEDURE; }
"function"              { strcpy(yylval.nd_obj.name,(yytext)); return FUNCTION; }
"return"                { strcpy(yylval.nd_obj.name,(yytext)); return RETURN; }
"while"                 { strcpy(yylval.nd_obj.name,(yytext)); return WHILE; }
"do"                    { strcpy(yylval.nd_obj.name,(yytext)); return DO; }
"if"                    { strcpy(yylval.nd_obj.name,(yytext)); return IF; }
"else"                  { strcpy(yylval.nd_obj.name,(yytext)); return ELSE; }
"for"                   { strcpy(yylval.nd_obj.name,(yytext)); return FOR; }
"switch"                { strcpy(yylval.nd_obj.name,(yytext)); return SWITCH; }
"case"                  { strcpy(yylval.nd_obj.name,(yytext)); return CASE; }
"break"                 { strcpy(yylval.nd_obj.name,(yytext)); return BREAK; }
"default"               { strcpy(yylval.nd_obj.name,(yytext)); return DEFAULT; }
"print"                 { strcpy(yylval.nd_obj.name,(yytext)); return PRINT; }
"scan"                  { strcpy(yylval.nd_obj.name,(yytext)); return SCAN; }
([\"].*?[\"])           { 
                           yylval.sValue = strdup(yytext);
                           return STRING_LITERAL;
                        }   
"printArray"            { strcpy(yylval.nd_obj.name,(yytext)); return PRINT_ARRAY; }
"true"                  { return TRUE; }
"false"                 { return FALSE; }
","                     { return COMMA; }
":"                     { return COLON; }
";"                     { return SEMI_COLON; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"["                     { return LBRACK; }
"]"                     { return RBRACK; }
"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
"."                     { return DOT; }
     
"++"                    { return INCREMENT; }
"--"                    { return DECREMENT; }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MULT; }
"/"                     { return DIVIDE; }
"%"                     { return MODULE; }
"+="                    { return ADD_ASSIGN; }
"-="                    { return SUB_ASSIGN; }
"*="                    { return MULT_ASSIGN; }
"/="                    { return DIVIDE_ASSIGN; }
"%="                    { return MODULE_ASSIGN; }
"="                     { return ASSIGN; }
     
"=="                    { return EQ; }
"!="                    { return NEQ; }
"<"                     { return LT; }
"<="                    { return LE; }
">"                     { return GT; }
">="                    { return GE; }

"&"                     { return AND; }
"|"                     { return OR; }
"!"                     { return NOT; }


[a-zA-Z][a-zA-Z0-9_]*   { yylval.sValue = strdup(yytext); return ID; }

.                       {printf ("Invalid character.");}

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif