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

%token INT FLOAT DOUBLE STRING BOOL ENUM POINTER
%token MAIN PROCEDURE FUNCTION RETURN
%token WHILE DO IF ELSE FOR SWITCH CASE BREAK DEFAULT PRINT SCAN PRINT_ARRAY
%token TRUE FALSE COMMA COLON SEMI_COLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT
%token INCREMENT DECREMENT PLUS MINUS MULT DIVIDE MODULE ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIVIDE_ASSIGN MODULE_ASSIGN ASSIGN
%token EQ NEQ LT LE GT GE AND OR NOT

%left PLUS MINUS
%left MULT DIVIDE MODULE

%start prog

//%type <sValue> stm

%%
prog :  decls_opt subprogrs  {} 
	 ;

decls_opt : decls {}
          |
		  ;
		  
decls : decl  {}
      | decls decl {}
	  ;

decl : type dimen_op ids SEMI_COLON {}
     ;

dimen_op : LBRACK RBRACK          {}
         | dimen_op LBRACK RBRACK {}
		 |
		 ;

ids : ids COMMA ID                {}
    | ID assign_op expr           {}
	| ID                          {}
    | ids COMMA ID assign_op expr {}
	;


subprogrs : subprog           {}
		  | subprogrs subprog {}
		  ;

subprog : procedure {}
		| function  {}
		;

procedure : PROCEDURE ID LPAREN args_op RPAREN LBRACE stmt_list RBRACE {}
          ;

function : FUNCTION ID LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE   {}
		 | FUNCTION MAIN LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE {}
		 ;

args_op : args {}
        |
		;

args : args COMMA arg   {}
	 | arg {}
	 ;

arg : type dimen_op ID {}
    ;

type : INT      {}
     | DOUBLE   {}
     | FLOAT    {}
     | STRING   {}
     | BOOL     {}
     ;

stmt_list : stmt           {}
		  | stmt_list stmt {} 
		  ;

stmt : while_stmt					     	 {}
	 | if_stmt                               {}
	 | decl                                  {}
     | for_stmt                              {}
	 | inc_dec SEMI_COLON                    {}
	 | assign_stmt SEMI_COLON                {} 
     | print_stmt  SEMI_COLON                {}
     | scan_stmt                             {}
	 | return_stmt                           {}
     ;

return_stmt : RETURN expr SEMI_COLON         {}
            ;
/*
decls : decl {}
	  | decls SEMI_COLON decl {}
	  ;


decl : assign_stmt                           {} 
     | print_stmt                            {}
     | scan_stmt                             {}
     | type ID                               {}
     | inc_dec                               {}
     | RETURN expr                           {}
     ;
*/

assign_stmt : ID dimen_ind_op assign_op expr   {}
			;

dimen_ind_op : LBRACK ind_op RBRACK dimen_ind_op {} 
			 |
			 ;

ind_op : ID {}
	   | INT_NUMBER {}
	   |
	   ;

assign_op : ASSIGN {}
          | ADD_ASSIGN {}
          | SUB_ASSIGN {}
          | MULT_ASSIGN {}
          | DIVIDE_ASSIGN {}
          | MODULE_ASSIGN {}
          ;

expr : ID                 {}
     | INT_NUMBER         {}
     | DOUBLE_NUMBER      {}
	 | STRING_LITERAL     {}
	 | TRUE               {}
	 | FALSE              {}
     | expr PLUS expr     {}
     | expr MINUS expr    {}
     | expr MULT expr     {}
     | expr DIVIDE expr   {}
     | expr MODULE expr   {}
	 ;

while_stmt : WHILE LPAREN condition RPAREN LBRACE stmt_list RBRACE               {}
           | DO LBRACE stmt_list RBRACE WHILE LPAREN condition RPAREN SEMI_COLON {}
		   ;

if_stmt : IF LPAREN condition RPAREN LBRACE stmt_list RBRACE {}
		;

for_stmt : FOR LPAREN for_args RPAREN LBRACE stmt_list RBRACE   {} 
         ;

for_args : assign_stmt SEMI_COLON ID comp_op ID SEMI_COLON inc_dec {}
		 ;

inc_dec : ID INCREMENT {}
        | ID DECREMENT {}
		| INCREMENT ID {}
		| DECREMENT ID {}
		;

print_stmt : PRINT LPAREN expr RPAREN {}
           ;

scan_stmt : SCAN LPAREN ID RPAREN {}
		  ; 

condition : condition logic_op c_term {}
          | c_term                    {}
		  ;

c_term : ID    {}
       | TRUE  {}
	   | FALSE {}
	   | comp  {}
	   ;
	   
comp : comp_term comp_op comp_term {}
     ;

comp_term : expr {}
          ;

comp_op : EQ  {}
        | NEQ {}
		| GE  {}
		| LE  {}
		| GT  {}
		| LT  {}
		;

logic_op : AND {}
         | OR  {}
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