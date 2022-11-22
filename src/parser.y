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
    int    iValue;  /* integer value */
    float  dValue;   /* double value */
    char   cValue;  /* char value */
    char * sValue;  /* string value */
};

%token <sValue> ID STRING_LITERAL
%token <iValue> INT_NUMBER
%token <dValue> DOUBLE_NUMBER

%token INT FLOAT DOUBLE STRING BOOL ENUM POINTER POINT_TO
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
prog : decls_opt subprogrs  {} 
     ;

decls_opt : decls  {}
          |
          ;
          
decls : decls decl  {}
      | decl        {}
      ;

decl : type dimen_op_opt ids SEMI_COLON     {}
     | decl_init_list                   {}
     | pointer_decl                      {}
     ;

decl_init_list : type LBRACK RBRACK ids SEMI_COLON {}
               ;

/*
list: INT_NUMBER                {}
    | INT_NUMBER COMMA list     {}
    | DOUBLE_NUMBER             {}
    | DOUBLE_NUMBER COMMA list  {}
    | STRING_LITERAL            {}
    | STRING_LITERAL COMMA list {}
    | TRUE                      {}
    | TRUE COMMA list           {}
    | FALSE                     {}
    | FALSE COMMA list          {}
    ;
*/

dimen_op_opt : dimen_ops {}
             |
             ;

dimen_ops : dimen_ops dimen_op {}
          | dimen_op {}
          ;

dimen_op : LBRACK num_expr RBRACK               {}
         ; 

pointer_decl : POINTER LT pointer_type GT ids SEMI_COLON {}
             ;
                         
pointer_type : type 
             | POINTER LT pointer_type GT {}
             ;

pointer_method: ID DOT POINT_TO LPAREN ID RPAREN SEMI_COLON {}
              ;

ids : ID assign_op LBRACE expr_list RBRACE  {}
    | ids COMMA ID assign_op expr           {}
    | ID assign_op expr                     {}
    | ids COMMA ID                          {}
    | ID                                    {}
    ;

expr_list : expr_list COMMA expr {}
          | expr {}
          ;

subprogrs : subprogrs subprog  {}
          | subprog           {}
          ;

subprog : procedure {}
        | function  {}
        ;

procedure : PROCEDURE ID LPAREN args_op RPAREN LBRACE stmt_list RBRACE {}
          ;

function : FUNCTION ID LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE   {}
         | FUNCTION MAIN LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE {}
         ;

args_op : args  {}
        |
        ;

args : args COMMA arg  {}
     | arg {}
     ;

arg : type dimen_op ID  {}
    | pointer_type ID   {}
    ;

type : INT     {}
     | DOUBLE  {}
     | FLOAT   {}
     | STRING  {}
     | BOOL    {}
     ;

stmt_list : stmt_list stmt  {}
          | stmt            {} 
          ;

stmt : while_stmt                            {}
     | if_stmt                               {}
     | decl                                  {}
     | for_stmt                              {}
     | switch_stmt                           {}
     | inc_dec SEMI_COLON                    {}
     | assign_stmt SEMI_COLON                {} 
     | print_stmt  SEMI_COLON                {}
     | scan_stmt SEMI_COLON                  {}
     | return_stmt                           {}
     | func_call SEMI_COLON                  {}
     | pointer_method                        {}
     ;

func_call : ID LPAREN func_args RPAREN  {} 
          ;

func_args : func_args COMMA expr {}
          | expr {}
          ;

return_stmt : RETURN expr SEMI_COLON  {}
            ;

assign_stmt : ID dimen_ind_op assign_op expr  {}
            ;

dimen_ind_op : LBRACK ind_op RBRACK dimen_ind_op {} 
             |
             ;

ind_op : num_expr {}
       | 
       ;

assign_op : ASSIGN        {}
          | ADD_ASSIGN    {}
          | SUB_ASSIGN    {}
          | MULT_ASSIGN   {}
          | DIVIDE_ASSIGN {}
          | MODULE_ASSIGN {}
          ;

expr : ID dimen_ind_op    {}
     | INT_NUMBER         {}
     | DOUBLE_NUMBER      {}
     | STRING_LITERAL     {}
     | TRUE               {}
     | FALSE              {}
     | func_call          {}
     | LPAREN expr RPAREN {}
     | expr PLUS expr     {}
     | expr MINUS expr    {}
     | expr MULT expr     {}
     | expr DIVIDE expr   {}
     | expr MODULE expr   {}
     ;

num_expr : ID                         {}
         | INT_NUMBER                 {}
         | LPAREN num_expr RPAREN     {}
         | num_expr PLUS num_expr     {}
         | num_expr MINUS num_expr    {}
         | num_expr MULT num_expr     {}
         | num_expr DIVIDE num_expr   {}
         | num_expr MODULE num_expr   {}
         ; 

while_stmt : WHILE LPAREN condition RPAREN LBRACE stmt_list RBRACE               {}
           | DO LBRACE stmt_list RBRACE WHILE LPAREN condition RPAREN SEMI_COLON {}
           ;

if_stmt : IF LPAREN condition RPAREN LBRACE stmt_list RBRACE else_stmt_opt {}
        ;

else_stmt_opt : ELSE LBRACE stmt_list RBRACE {}
              |                              {}
              ;
          
for_stmt : FOR LPAREN for_args RPAREN LBRACE stmt_list RBRACE  {} 
         ;

for_args : assign_stmt SEMI_COLON ID comp_op ID SEMI_COLON inc_dec  {}
         | decls ID comp_op ID SEMI_COLON inc_dec        {}
         ;

inc_dec : ID INCREMENT {}
        | ID DECREMENT {}
        | INCREMENT ID {}
        | DECREMENT ID {}
        ;

print_stmt : PRINT LPAREN expr RPAREN {}
           ;

scan_stmt : SCAN LPAREN ID dimen_ind_op RPAREN {}
          ; 

switch_stmt : SWITCH LPAREN expr RPAREN LBRACE switch_cases RBRACE {}
            ;

switch_cases : switch_cases case {} 
             | case              {}
             ;

case : CASE INT_NUMBER COLON stmt_list BREAK SEMI_COLON      {}
     | CASE DOUBLE_NUMBER COLON stmt_list BREAK SEMI_COLON   {}
     | CASE STRING_LITERAL COLON stmt_list BREAK SEMI_COLON  {}
     | CASE TRUE COLON stmt_list BREAK SEMI_COLON            {}
     | CASE FALSE COLON stmt_list BREAK SEMI_COLON           {}
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