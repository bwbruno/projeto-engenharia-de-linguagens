/*

lex example4.l
yacc example4.y -d -v -g  (-d: y.tab.h; -v: y.output; -g: y.dot [GraphViz])
gcc lex.yy.c y.tab.c -o parser.exe 

*/

%{
#include "symboltable.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE *yyin;
extern FILE *yyout;

struct node *head;

struct node { 
struct node *left; 
struct node *right; 
char *token; 
};

void printtree(struct node*);
void printInorder(struct node *);
void printPreorder(struct node *);
struct node* mknode(struct node *left, struct node *right, char *token);

%}


%union {
    int    iValue;   /* integer value */
    float  fValue;   /* double value */
    double dValue;   /* double value */
    char   cValue;   /* char value */
    char *sValue;    /* string value */
    struct bucket *symbol;
    struct var_name { 
        char name[100]; 
        struct node* nd;
    } nd_obj; 
};

%token <sValue> STRING_LITERAL
%token <iValue> INT_NUMBER
%token <fValue> DOUBLE_NUMBER
%token <symbol> ID

%token INT FLOAT DOUBLE STRING BOOL ENUM POINTER POINT_TO
%token <nd_obj> MAIN PROCEDURE FUNCTION RETURN
%token <nd_obj> WHILE DO IF ELSE FOR SWITCH CASE BREAK DEFAULT PRINT SCAN PRINT_ARRAY
%token TRUE FALSE COMMA COLON SEMI_COLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT
%token INCREMENT DECREMENT PLUS MINUS MULT DIVIDE MODULE ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIVIDE_ASSIGN MODULE_ASSIGN ASSIGN
%token EQ NEQ LT LE GT GE AND OR NOT

%left PLUS MINUS
%left MULT DIVIDE MODULE

%type <symbol> ids procedure function
%type <nd_obj> prog decls_opt subprogrs decls decl type dimen_op_opt decl_init_list pointer_decl dimen_ops dimen_op num_expr pointer_type pointer_method assign_op expr_list expr subprog args_op stmt_list args arg stmt while_stmt if_stmt assign_stmt for_stmt switch_stmt inc_dec print_stmt scan_stmt return_stmt func_call func_args dimen_ind_op ind_op condition else_stmt_opt for_args comp_op switch_cases case logic_op c_term comp comp_term 

%start prog

//%type <sValue> stm

%%
prog : decls_opt subprogrs  {} 
     ;

decls_opt : decls  {}
          |        {}
          ;
          
decls : decls decl  {}
      | decl        {}
      ;

decl : type dimen_op_opt  ids SEMI_COLON   {}
     | decl_init_list                      {}
     | pointer_decl                        {}
     ;

decl_init_list : type LBRACK RBRACK ids {} SEMI_COLON {}
               ;

dimen_op_opt : dimen_ops {}
             |           {}
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
          | expr                 {}
          ;

subprogrs : subprogrs { begin_scope(); } subprog  { end_scope(); }
          | { begin_scope(); } subprog { end_scope(); }
          ;

subprog : procedure {}
        | function  {}
        ;

procedure : PROCEDURE ID LPAREN args_op RPAREN LBRACE stmt_list RBRACE              {}
          ;

function : FUNCTION ID LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE     {}
         | FUNCTION MAIN LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE   {}
         ;

args_op : args  {}
        |       {}
        ;

args : args COMMA arg {}
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

stmt_list : stmt_list stmt 
          | stmt 
          ;

stmt : while_stmt                            {}
     | if_stmt                               {}
     | assign_stmt SEMI_COLON                {} 
     | decl                                  {} 
     | for_stmt                              {}
     | switch_stmt                           {}
     | inc_dec SEMI_COLON                    {}
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
             | {}
             ;

ind_op : num_expr {}
       |          {} 
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

while_stmt : WHILE LPAREN condition RPAREN { begin_scope(); } LBRACE stmt_list RBRACE               { end_scope(); }
           | DO { begin_scope(); } LBRACE stmt_list RBRACE WHILE LPAREN condition RPAREN SEMI_COLON { end_scope(); }
           ;

if_stmt : IF LPAREN condition RPAREN { begin_scope(); } LBRACE stmt_list RBRACE { scope--; } else_stmt_opt {}
        ;

else_stmt_opt : ELSE { scope += 2; } LBRACE stmt_list RBRACE { end_scope(); }
              |                              {}
              ;
          
for_stmt : FOR { begin_scope(); } LPAREN for_args RPAREN LBRACE stmt_list RBRACE  { end_scope(); } 
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

int main (int argc, char *argv[]) {
    malloc_hashtable();

    yyparse();

    if (strcmp("--dump-symboltable", argv[1]) == 0 && (argc > 2)) {
       	yyout = fopen(argv[2], "w");
        dump_symboltable(yyout);
        fclose(yyout);
    }
    
    return 0;
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void printtree(struct node* tree) {
	printf("\n\n Printing Parse Tree: \n\n");
	printPreorder(tree);
	printf("\n\n");
}

void printInorder(struct node *tree) {
	
	if (tree == NULL)
        return;

	if (tree->left) {
		printInorder(tree->left);
	}

	printf("%s, ", tree->token);

	if (tree->right) {
		printInorder(tree->right);
	}
}

void printPreorder(struct node *tree)
{
    printf("[");

	printf("%s ", tree->token);

	if (tree->left){
		printPreorder(tree->left);
	}

	if (tree->right){
		printPreorder(tree->right);
	}

	printf("]");
}

void yyerror (char *msg) {
    fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    exit(1);
}
