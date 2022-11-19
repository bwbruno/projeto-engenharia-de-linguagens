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
%token TRUE FALSE COMMA COLON SEMI_COLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT
%token INCREMENT DECREMENT PLUS MINUS MULT DIVIDE MODULE ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIVIDE_ASSIGN MODULE_ASSIGN ASSIGN
%token EQ NEQ LT LE GT GE AND OR NOT

%start prog

//%type <sValue> stm

%%
prog :  subprogrs  {} 
	 ;

subprogrs : subprog {}
		  | subprogrs subprog {}
		  ;

subprog : procedure {}
		| function {}
		;

procedure : PROCEDURE ID LPAREN args RPAREN LBRACE stmt_list RBRACE {}
          ;

function : FUNCTION ID LPAREN args RPAREN COLON type LBRACE stmt_list RBRACE {}
		 ;

args : type ID {}
	 | args COMMA type ID {}
	 |
	 ;

type : INT      {}
     | DOUBLE   {}
     | STRING   {}
     | BOOL  {}
     ;

stmt_list : stmt {}
		  | stmt_list SEMI_COLON stmt {} 
		  ;



stmt : assign_stmt                           {}
     | while_stmt					     	 {}
	 /*
	 | if_stmt                               {}
     | switch_stmt                           {}
     | for_stmt                              {}
     | ID INCREMENT                          {}
     | ID DECREMENT                          {}
     | decl                                  {}
     | print_stmt                            {}
     | scan_stmt                             {}
	 */
	 |
     ;

assign_stmt : ID assign_op expr {}
			;

assign_op : ASSIGN {}
          | ADD_ASSIGN {}
          | SUB_ASSIGN {}
          | MULT_ASSIGN {}
          | DIVIDE_ASSIGN {}
          | MODULE_ASSIGN {}
          ;

expr : INT_NUMBER {}
     | DOUBLE_NUMBER {}
	 | STRING_LITERAL {}
	 | TRUE {}
	 | FALSE {}
	 ;

while_stmt : WHILE LPAREN condition RPAREN LBRACE stmt_list RBRACE {}
           | DO stmt_list WHILE LPAREN condition RPAREN {}
		   ;

condition : condition logic_op c_term {}
          | c_term {}
		  ;

c_term : ID {}
       | TRUE {}
	   | FALSE {}
	   | comp {}
	   ;
	   
comp : comp_term comp_op comp_term {}
     ;

comp_term : expr {}
          ;

comp_op : EQ {}
        | NEQ {}
		| GE {}
		| LE {}
		| GT {}
		| LT {}
		;

logic_op : AND {}
         | OR {}
		 | NOT {}
		 ;
%%

int main (void) {
	return yyparse ( );
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}