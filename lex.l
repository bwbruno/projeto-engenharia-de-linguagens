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
%}

%%

[ \t\n]               ;
[0-9]*                { printf("INTNUMBER(%s)\n",yytext); }
((\+|-)?([0-9]+)(\.[0-9]+)?)|((\+|-)?\.?[0-9]+) { printf("DOUBLE_NUMBER(%s)\n",yytext); }
"int"                { printf("INT\n"); }
"double"                { printf("DOUBLE\n"); }
"bool"                { printf("BOOL\n"); }
"string"                { printf("STRING\n)"); }
"enum"                { printf("ENUM\n"); }
"pointer"                { printf("POINTER\n"); }

"procedure"                { printf("PROCEDURE\n"); }
"function"                { printf("FUNCTION\n"); }
"return"                { printf("RETURN\n"); }
"while"               { printf("WHILE\n"); }
"do"                  { printf("DO\n"); }
"if"                  { printf("IF\n"); }
"else"                { printf("ELSE\n"); }
"for"                { printf("FOR\n"); }
"switch"                { printf("SWITCH\n"); }
"case"                { printf("CASE\n"); }
"break"                { printf("BREAK\n"); }
"default"                { printf("DEFAULT\n"); }
"print"                { printf("PRINT\n"); }
"scan"                { printf("SCAN\n"); }
([\"].*?[\"])  { printf("STRING_LITERAL(%s)\n",yytext); }   

"printArray"       { printf("PRINTARRAY\n"); }

"true"             { printf("TRUE\n"); }
"false"            { printf("FALSE\n"); }
","                { printf("COMMA\n"); }
":"                { printf("COLON\n"); }
";"                { printf("SEMICOLON\n"); }
"("                { printf("LPAREN\n"); }
")"                { printf("RPAREN\n"); }
"["                { printf("LBRACK\n"); }
"]"                { printf("RBRACK\n"); }
"{"                { printf("LBRACE\n"); }
"}"                { printf("RBRACE\n"); }
"."                { printf("DOT\n"); }

"++"               { printf("INCREMENT\n"); }
"--"               { printf("DECREMENT\n"); }
"+"                { printf("PLUS\n"); }
"-"                { printf("MINUS\n"); }
"*"                { printf("MULT\n"); }
"/"                { printf("DIVIDE\n"); }
"%"                { printf("MODULE\n"); }
"+="               { printf("ADD_ASSIGN\n"); }
"-="               { printf("SUB_ASSIGN\n"); }
"*="               { printf("MULT_ASSIGN\n"); }
"/="               { printf("DIVIDE_ASSIGN\n"); }
"%="               { printf("DIVIDE_ASSIGN\n"); }
"="                { printf("ASSIGN\n"); }

"=="               { printf("EQ\n"); }
"!="               { printf("NEQ\n"); }
"<"                { printf("LT\n"); }
"<="               { printf("LE\n"); }
">"                { printf("GT\n"); }
">="               { printf("GE\n"); }
"&"                { printf("AND\n"); }
"|"                { printf("OR\n"); }

[a-zA-Z][a-zA-Z0-9_]*               {printf("ID(%s)\n",yytext);}

.               {printf("Invalid character.\n");}

%%

#ifndef yywrap
int yywrap (void) {
	return 1;
}
#endif

int main(int argc, char * argv[])
{
	yyin = fopen(argv[1], "r");
	
	yylex();  
	
	fclose(yyin);
	
	return 0;
}
