/*

lex example4.l
yacc example4.y -d -v -g  (-d: y.tab.h; -v: y.output; -g: y.dot [GraphViz])
gcc lex.yy.c y.tab.c -o parser.exe 

*/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;

%}

%union {
	int    iValue; 	/* integer value */
    float  dValue;   /* double value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
};

%token <sValue> ID STRING_LITERAL
%token <iValue> INT_NUMBER
%token <dValue> DOUBLE_NUMBER
%token INT DOUBLE STRING BOOL ENUM POINTER
%token PROCEDURE FUNCTION RETURN
%token WHILE DO IF ELSE FOR SWITCH CASE BREAK DEFAULT PRINT SCAN PRINT_ARRAY
%token TRUE FALSE COMMA COLON SEMI SEMI_COLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT
%token INCREMENT DECREMENT PLUS MINUS MULT DIVIDE MODULE ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIVIDE_ASSIGN MODULE_ASSIGN ASSIGN
%token EQ NEQ LT LE GT GE AND OR

%start prog

%type <sValue> stm

%%
prog : stmlist {} 
	 ;

stm : ID ASSIGN ID                          {printf("%s = %s\n", $1, $3);}
    | WHILE ID DO stm						{}
	;
	
stmlist : stm								{}
		| stmlist SEMI stm   				{}
	    ;
%%

int main (void) {
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}