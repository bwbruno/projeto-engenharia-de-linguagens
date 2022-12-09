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
char *fileStack = NULL;
char *fileSymbolTable = NULL;
struct stack *scopes;
int line = 1;

%}

%option yylineno

%%

[ \t]                   ;
[\n]                    {
                           if(fileStack) {
                              dump_stack(scopes, fileStack, line++);
                           }
                        }
[0-9]+                  { strcpy(yylval.nd_obj.name,(yytext)); return INT_NUMBER; }

([0-9]+)(\.[0-9]+)?|\.?[0-9]+ {
                           strcpy(yylval.nd_obj.name,(yytext));
                           return DOUBLE_NUMBER;
                        }

"int"                   { strcpy(yylval.nd_obj.name,(yytext)); return INT; }
"double"                { strcpy(yylval.nd_obj.name,(yytext)); return DOUBLE; }
"bool"                  { strcpy(yylval.nd_obj.name,(yytext)); return BOOL; }
"float"                 { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT; }
"string"                { strcpy(yylval.nd_obj.name,(yytext)); return STRING; }
"enum"                  { strcpy(yylval.nd_obj.name,(yytext)); return ENUM; }
"pointer"               { strcpy(yylval.nd_obj.name,(yytext)); return POINTER; }
"pointTo"               { strcpy(yylval.nd_obj.name,(yytext)); return POINT_TO; }
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
([\"].*?[\"])           { strcpy(yylval.nd_obj.name,(yytext)); return STRING_LITERAL; }   
"printArray"            { strcpy(yylval.nd_obj.name,(yytext)); return PRINT_ARRAY; }
"true"                  { strcpy(yylval.nd_obj.name,(yytext)); return TRUE; }
"false"                 { strcpy(yylval.nd_obj.name,(yytext)); return FALSE; }
","                     { strcpy(yylval.nd_obj.name,(yytext)); return COMMA; }
":"                     { strcpy(yylval.nd_obj.name,(yytext)); return COLON; }
";"                     { strcpy(yylval.nd_obj.name,(yytext)); return SEMI_COLON; }
"("                     { strcpy(yylval.nd_obj.name,(yytext)); return LPAREN; }
")"                     { strcpy(yylval.nd_obj.name,(yytext)); return RPAREN; }
"["                     { strcpy(yylval.nd_obj.name,(yytext)); return LBRACK; }
"]"                     { strcpy(yylval.nd_obj.name,(yytext)); return RBRACK; }
"{"                     { strcpy(yylval.nd_obj.name,(yytext)); return LBRACE; }
"}"                     { strcpy(yylval.nd_obj.name,(yytext)); return RBRACE; }
"."                     { strcpy(yylval.nd_obj.name,(yytext)); return DOT; }

"++"                    { strcpy(yylval.nd_obj.name,(yytext)); return INCREMENT; }
"--"                    { strcpy(yylval.nd_obj.name,(yytext)); return DECREMENT; }
"+"                     { strcpy(yylval.nd_obj.name,(yytext)); return PLUS; }
"-"                     { strcpy(yylval.nd_obj.name,(yytext)); return MINUS; }
"*"                     { strcpy(yylval.nd_obj.name,(yytext)); return MULT; }
"/"                     { strcpy(yylval.nd_obj.name,(yytext)); return DIVIDE; }
"%"                     { strcpy(yylval.nd_obj.name,(yytext)); return MODULE; }
"+="                    { strcpy(yylval.nd_obj.name,(yytext)); return ADD_ASSIGN; }
"-="                    { strcpy(yylval.nd_obj.name,(yytext)); return SUB_ASSIGN; }
"*="                    { strcpy(yylval.nd_obj.name,(yytext)); return MULT_ASSIGN; }
"/="                    { strcpy(yylval.nd_obj.name,(yytext)); return DIVIDE_ASSIGN; }
"%="                    { strcpy(yylval.nd_obj.name,(yytext)); return MODULE_ASSIGN; }
"="                     { strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN; }

"=="                    { strcpy(yylval.nd_obj.name,(yytext)); return EQ; }
"!="                    { strcpy(yylval.nd_obj.name,(yytext)); return NEQ; }
"<"                     { strcpy(yylval.nd_obj.name,(yytext)); return LT; }
"<="                    { strcpy(yylval.nd_obj.name,(yytext)); return LE; }
">"                     { strcpy(yylval.nd_obj.name,(yytext)); return GT; }
">="                    { strcpy(yylval.nd_obj.name,(yytext)); return GE; }

"&"                     { strcpy(yylval.nd_obj.name,(yytext)); return AND; }
"|"                     { strcpy(yylval.nd_obj.name,(yytext)); return OR; }
"!"                     { strcpy(yylval.nd_obj.name,(yytext)); return NOT; }


[a-zA-Z][a-zA-Z0-9_]*   { strcpy(yylval.nd_obj.name,(yytext)); return ID; }

.                       { printf ("Invalid character."); }

%%

#ifndef yywrap
   int yywrap (void) { return 1; }
#endif
