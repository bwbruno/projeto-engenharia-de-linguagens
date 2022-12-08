%{
#include "stack.c"
#include "symboltable.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *s);
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern FILE *yyout;

char buffer[SIZE_TEXT];
struct stack *scopes;
struct node *parsetree;
int idScope = 1;
char auxScope[10];

struct node { 
    struct node *left; 
    struct node *right; 
    char *token; 
};

typedef union Value{
    int iValue;   /* integer value */
    float fValue; /* double value  */
    double dValue;/* double value  */
    char cValue;  /* char value    */
    char *sValue; /* string value  */
} Value;

void print_tree(struct node*);
void print_preorder(struct node *);
struct node* mknode(struct node *left, struct node *right, char *token);
char *insert_key(char *id);

%}


%union {
    union Value *value;
    struct bucket *symbol;
    struct var_name { 
        char name[100]; 
        struct node* nd;
    } nd_obj; 
};

%token <nd_obj> STRING_LITERAL
%token <nd_obj> INT_NUMBER
%token <nd_obj> DOUBLE_NUMBER
%token <nd_obj> ID
%token <nd_obj> INT FLOAT DOUBLE STRING BOOL ENUM POINTER POINT_TO
%token <nd_obj> MAIN PROCEDURE FUNCTION RETURN
%token <nd_obj> WHILE DO IF ELSE FOR SWITCH CASE BREAK DEFAULT PRINT SCAN PRINT_ARRAY
%token <nd_obj> TRUE FALSE COMMA COLON SEMI_COLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT
%token <nd_obj> INCREMENT DECREMENT PLUS MINUS MULT DIVIDE MODULE ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIVIDE_ASSIGN MODULE_ASSIGN ASSIGN
%token <nd_obj> EQ NEQ LT LE GT GE AND OR NOT

%left PLUS MINUS
%left MULT DIVIDE MODULE

%type <nd_obj> ids procedure function
%type <nd_obj> prog decls_opt subprogrs decls decl type dimen_op_opt decl_init_list pointer_decl dimen_ops dimen_op num_expr pointer_type pointer_method assign_op expr_list expr subprog args_op stmt_list args arg stmt while_stmt if_stmt assign_stmt for_stmt switch_stmt inc_dec print_stmt scan_stmt return_stmt func_call func_args dimen_ind_op ind_op condition else_stmt_opt for_args comp_op switch_cases case logic_op c_term comp comp_term 

%start prog

//%type <sValue> stm

%%
prog : { push(scopes, "0"); } decls_opt subprogrs  
       {
         $$.nd = mknode($2.nd, $3.nd, "prog");
         parsetree = $$.nd;
         //pop(scopes);
       }
       ;

decls_opt : decls  
            {
                $$.nd = mknode($1.nd, NULL, "decls-opt");
            }
            | { printf("decls_opt:: \n"); $$.nd = NULL; }
            ;
          
decls : decls decl
        {
          $$.nd = mknode($1.nd, $2.nd, "decls");
        }
        |  decl
        {
          $$.nd = mknode($1.nd, NULL, "decl");
        }
        ;

decl : type dimen_op_opt ids SEMI_COLON
       { 
         struct node *temp = mknode($1.nd, $2.nd, "type");
         $$.nd = mknode(temp, $3.nd, "ids");
       }
       | decl_init_list
       {
         $$.nd = mknode($1.nd, NULL, "decl");
       }
       | pointer_decl
       {
         $$.nd = mknode($1.nd, NULL, "decl");
       }
       ;

decl_init_list : type LBRACK RBRACK ids SEMI_COLON
                 {
                   struct node *temp = mknode($1.nd, NULL, "ids");
                   $$.nd = mknode(temp, NULL, "decl-init-list");
                 }
                 ;

dimen_op_opt : dimen_ops
               {
                 $$.nd = mknode($1.nd, NULL, "decl-op-opt");
               }
               | { $$.nd = NULL; }
               ;

dimen_ops : dimen_ops dimen_op
            {
              $$.nd = mknode($1.nd, $2.nd, "decl-ops");
            }
            | dimen_op
            {
              $$.nd = mknode($1.nd, NULL, "decl-op");
            }
            ;

dimen_op : LBRACK num_expr RBRACK
           {
             $$.nd = mknode($2.nd, NULL, "decl-op");
           }
           ; 

pointer_decl : POINTER LT pointer_type GT ids SEMI_COLON
               {
                 struct node *temp = mknode($3.nd, NULL, "ids");
                 $$.nd = mknode(temp, NULL, "pointer-decl");
               }
               ;
                         
pointer_type : type 
               {
                 $$.nd = mknode($1.nd, NULL, "type");
               }
               | POINTER LT pointer_type GT
               {
                 $$.nd = mknode($3.nd, NULL, "pointer-type");
               }
               ;

pointer_method : ID DOT POINT_TO LPAREN ID RPAREN SEMI_COLON {}
               ;

ids : ID assign_op LBRACE expr_list RBRACE
      {
          printf("ids: %s at line %d\n", insert_key($1.name), yylineno);
          $$.nd = mknode($2.nd, $4.nd, $1.name);
      }
      | ids COMMA ID assign_op expr
      {
          printf("ids: %s at line %d\n", $3.name, yylineno);
          $$.nd = mknode($4.nd, $5.nd, "ids");
      }
      | ID assign_op expr
      {
          printf("ids: %s at line %d\n", insert_key($1.name), yylineno);
          $$.nd = mknode($2.nd, $3.nd, $1.name);
      }
      | ids COMMA ID
      {
          printf("ids: %s at line %d\n", $3.name, yylineno);
          $$.nd = mknode($1.nd, NULL, "ids");
      }
      | ID
      {
          printf("ids: %s at line %d\n", insert_key($1.name), yylineno);
          $$.nd = mknode(NULL, NULL, $1.name);
      }
      ;

expr_list : expr_list COMMA expr 
            {
                $$.nd = mknode($1.nd, $3.nd, "expr-list");
            }
            | expr                 
            {
                $$.nd = mknode($1.nd, NULL, "expr");
            }
            ;

subprogrs : subprogrs subprog  
            {
                $$.nd = mknode($1.nd, $2.nd, "subprogrs");
            }
            | subprog 
            {
                $$.nd = mknode($1.nd, NULL, "subprog");
            }
            ;

subprog : procedure
          {
              $$.nd = mknode($1.nd, NULL, "procedure");
          }
          | function
          {
              $$.nd = mknode($1.nd, NULL, "function");
          }
          ;

procedure : PROCEDURE ID LPAREN args_op RPAREN LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE {pop(scopes);}
            {
                $$.nd = mknode($4.nd, $8.nd, $2.name);
            }
            ;

function : FUNCTION ID LPAREN args_op RPAREN COLON type LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE {pop(scopes);}
           {
               struct node *temp = mknode($4.nd, $10.nd, $2.name);
               $$.nd = mknode($7.nd, temp, "type");
           }
           | FUNCTION MAIN LPAREN args_op RPAREN COLON type LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE {pop(scopes);}
           {
               struct node *temp = mknode($4.nd, $10.nd, $2.name);
               $$.nd = mknode($7.nd, temp, "type");
           }
           ;

args_op : args
          {
              $$.nd = mknode($1.nd, NULL, "args-op");
          }
        | { $$.nd = NULL; }
        ;

args : args COMMA arg
       {
           $$.nd = mknode($1.nd, $3.nd, "args");
       }
       | arg
       {
           $$.nd = mknode($1.nd, NULL, "arg");
       }
       ;

arg : type dimen_op ID 
      {
          $$.nd = mknode($1.nd, $2.nd, $3.name);
      }
      | pointer_type ID  
      {
          $$.nd = mknode($1.nd, NULL, $2.name);
      }
      ;

type : INT     { $$.nd = mknode(NULL, NULL, $1.name); }
     | DOUBLE  { $$.nd = mknode(NULL, NULL, $1.name); }
     | FLOAT   { $$.nd = mknode(NULL, NULL, $1.name); }
     | STRING  { $$.nd = mknode(NULL, NULL, $1.name); }
     | BOOL    { $$.nd = mknode(NULL, NULL, $1.name); }
     ;

stmt_list : stmt_list stmt 
            {
                $$.nd = mknode($1.nd, $2.nd, "stmt_list");
            }
            | stmt
            {
                $$.nd = mknode($1.nd, NULL, "stmt");
            }
            ;

stmt : while_stmt
       {
           $$.nd = mknode($1.nd, NULL, "while-stmt");
       }
       | assign_stmt SEMI_COLON
       {
          $$.nd = mknode($1.nd, NULL, "assign-stmt");
       }
       | if_stmt
       {
          $$.nd = mknode($1.nd, NULL, "if-stmt");
       }
       | for_stmt
       {
          $$.nd = mknode($1.nd, NULL, "for-stmt");
       }
       | switch_stmt
       {
          $$.nd = mknode($1.nd, NULL, "switch-stmt");
       }
       | inc_dec SEMI_COLON
       {
          $$.nd = mknode($1.nd, NULL, "inc-dec");
       }
       | print_stmt  SEMI_COLON
       {
          $$.nd = mknode($1.nd, NULL, "print-stmt");
       }
       | scan_stmt SEMI_COLON
       {
          $$.nd = mknode($1.nd, NULL, "scan-stmt");
       }
       | return_stmt
       {
          $$.nd = mknode($1.nd, NULL, "return-stmt");
       }
       | func_call SEMI_COLON
       {
          $$.nd = mknode($1.nd, NULL, "func-call ");
       }
       | pointer_method
       {
          $$.nd = mknode($1.nd, NULL, "pointer-method");
       }
       | decl
       {
          $$.nd = mknode($1.nd, NULL, "decl");
       }
       ;

func_call : ID LPAREN func_args RPAREN 
            {
               $$.nd = mknode($3.nd, NULL, "func-call");
            }
            ;

func_args : func_args COMMA expr
            {
               $$.nd = mknode($1.nd, $3.nd, "func-args");
            }
            | expr
            {
               $$.nd = mknode($1.nd, NULL, "expr");
            }
            ;

return_stmt : RETURN expr SEMI_COLON
              {
                 $$.nd = mknode($2.nd, NULL, "expr");
              }
              ;

assign_stmt : ID dimen_ind_op assign_op expr
              {
                 //struct node *temp = mknode($2.nd, $4.nd, $1.name);
                 struct node *aux = mknode(NULL,NULL,$1.name);
                 $3.nd = mknode(aux, $4.nd, $3.name);
                 $$.nd = mknode($3.nd, NULL, "assign-op");
                 //$$.nd = mknode($3.nd, temp, "assign-op");
              }
              ;

dimen_ind_op : LBRACK ind_op RBRACK dimen_ind_op
               {
                  $$.nd = mknode($2.nd, $4.nd, "dimen-ind-op");
               }
               | { $$.nd = NULL; }
               ;

ind_op : num_expr
         {
            $$.nd = mknode($1.nd, NULL, "ind_op");
         }
         | { $$.nd = NULL; }
         ;

assign_op : ASSIGN        { $$.nd = mknode(NULL, NULL, $1.name); }
          | ADD_ASSIGN    { $$.nd = mknode(NULL, NULL, $1.name); }
          | SUB_ASSIGN    { $$.nd = mknode(NULL, NULL, $1.name); }
          | MULT_ASSIGN   { $$.nd = mknode(NULL, NULL, $1.name); }
          | DIVIDE_ASSIGN { $$.nd = mknode(NULL, NULL, $1.name); }
          | MODULE_ASSIGN { $$.nd = mknode(NULL, NULL, $1.name); }
          ;

expr : ID dimen_ind_op    
       {
          $$.nd = mknode($2.nd, NULL, $1.name);
       }
       | INT_NUMBER         
       {
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | DOUBLE_NUMBER      
       {
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | STRING_LITERAL     
       {
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | TRUE               
       {
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | FALSE              
       {
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | func_call          
       {
          $$.nd = mknode($1.nd, NULL, "func-call");
       }
       | LPAREN expr RPAREN 
       {
          $$.nd = mknode($2.nd, NULL, "expr");
       }
       | expr PLUS expr     
       {
          printf("\n\nexpr PLUS expr\n\n");
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr MINUS expr    
       {
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr MULT expr     
       {
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr DIVIDE expr   
       {
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr MODULE expr   
       {
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       ;

num_expr : ID
           {
              $$.nd = mknode(NULL, NULL, $1.name);
           }
           | INT_NUMBER
           {
              $$.nd = mknode(NULL, NULL, $1.name);
           }
           | LPAREN num_expr RPAREN
           {
              $$.nd = mknode($2.nd, NULL, "num-expr");
           }
           | num_expr PLUS num_expr
           {
              $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr MINUS num_expr
           {
              $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr MULT num_expr
           {
              $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr DIVIDE num_expr
           {
              $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr MODULE num_expr
           {
              $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           ; 

while_stmt : WHILE LPAREN condition RPAREN {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE {pop(scopes);}
             {
                $$.nd = mknode($3.nd, $7.nd, $1.name);
             }
             | DO LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE WHILE LPAREN condition RPAREN SEMI_COLON
             {
                $$.nd = mknode($4.nd, $8.nd, "do-while");
             }
             ;

if_stmt : IF LPAREN condition RPAREN LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE {pop(scopes);} else_stmt_opt
          {
             struct node *temp = mknode($7.nd, $10.nd, "body");
             $$.nd = mknode($3.nd, temp, "if-else");
          }
        ;

else_stmt_opt : ELSE LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} stmt_list RBRACE {pop(scopes);} 
                {
                   $$.nd = mknode($4.nd, NULL, $1.name);
                }
                | { $$.nd = NULL; }
                ;
          
for_stmt : FOR LPAREN {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} for_args RPAREN LBRACE  stmt_list RBRACE {pop(scopes);}
           {
              $$.nd = mknode($4.nd, $7.nd, $1.name);
           }
         ;

for_args : assign_stmt SEMI_COLON ID comp_op ID SEMI_COLON inc_dec  {}
         | decls ID comp_op ID SEMI_COLON inc_dec                   {}
         ;

inc_dec : ID INCREMENT {}
        | ID DECREMENT {}
        | INCREMENT ID {}
        | DECREMENT ID {}
        ;

print_stmt : PRINT LPAREN expr RPAREN
             {
                $$.nd = mknode($3.nd, NULL, $1.name);
             }
             ;

scan_stmt : SCAN LPAREN ID dimen_ind_op RPAREN
            {
               $$.nd = mknode($4.nd, NULL, $1.name);
            }
            ; 

switch_stmt : SWITCH LPAREN expr RPAREN LBRACE {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} switch_cases RBRACE {pop(scopes);}
              {
                 $$.nd = mknode($3.nd, $7.nd, $1.name);
              }
              ;

switch_cases : switch_cases case 
               {
                  $$.nd = mknode($1.nd, $2.nd, "switch-cases");
               }
               | case
               {
                  $$.nd = mknode($1.nd, NULL, "case");
               }
               ;

case : CASE INT_NUMBER COLON stmt_list BREAK SEMI_COLON      { $$.nd = mknode($4.nd, NULL, $1.name); }
     | CASE DOUBLE_NUMBER COLON stmt_list BREAK SEMI_COLON   { $$.nd = mknode($4.nd, NULL, $1.name); }
     | CASE STRING_LITERAL COLON stmt_list BREAK SEMI_COLON  { $$.nd = mknode($4.nd, NULL, $1.name); }
     | CASE TRUE COLON stmt_list BREAK SEMI_COLON            { $$.nd = mknode($4.nd, NULL, $1.name); }
     | CASE FALSE COLON stmt_list BREAK SEMI_COLON           { $$.nd = mknode($4.nd, NULL, $1.name); }
     ;

condition : condition logic_op c_term
            {
               struct node *temp = mknode($1.nd, $3.nd, "condition");
               $$.nd = mknode($2.nd, temp, "logic-op");
            }
            | c_term
            {
               $$.nd = mknode($1.nd, NULL, "c-term");
            }
            ;

c_term : ID    { $$.nd = mknode(NULL, NULL, $1.name); }
       | TRUE  { $$.nd = mknode(NULL, NULL, $1.name); }
       | FALSE { $$.nd = mknode(NULL, NULL, $1.name); }
       | comp  { $$.nd = mknode($1.nd, NULL, "comp"); }
       ;
       
comp : comp_term comp_op comp_term
       {
          struct node *temp = mknode($1.nd, $3.nd, "comp-op");
          $$.nd = mknode($2.nd, temp, "comp");
       }
       ;

comp_term : expr { $$.nd = mknode($1.nd, NULL, "expr"); }
          ;

comp_op : EQ  { $$.nd = mknode(NULL, NULL, $1.name); }
        | NEQ { $$.nd = mknode(NULL, NULL, $1.name); }
        | GE  { $$.nd = mknode(NULL, NULL, $1.name); }
        | LE  { $$.nd = mknode(NULL, NULL, $1.name); }
        | GT  { $$.nd = mknode(NULL, NULL, $1.name); }
        | LT  { $$.nd = mknode(NULL, NULL, $1.name); }
        ;

logic_op : AND { $$.nd = mknode(NULL, NULL, $1.name); }
         | OR  { $$.nd = mknode(NULL, NULL, $1.name); }
         | NOT { $$.nd = mknode(NULL, NULL, $1.name); }
         ;

%%

int main (int argc, char *argv[]) {
    scopes = malloc_stack();
    malloc_hashtable();

    yyparse();

    if ((argc > 2) && strcmp("--dump-symboltable", argv[1]) == 0) {
        char *filename = argv[2];
        yyout = fopen(filename, "w");
        dump_symboltable(yyout);
        fclose(yyout);
    }

    print_tree(parsetree);
    print_stack(scopes);
    
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

void print_tree(struct node* tree) {
    printf("\n\nPrinting Parse Tree:\n");
    print_preorder(tree);
    printf("\nCopie e cole o resultado no site: http://mshang.ca/syntree/\n\n");
}

void print_preorder(struct node *tree)
{
    printf("[");

    printf("%s ", tree->token);

    if (tree->left){
        print_preorder(tree->left);
    }

    if (tree->right){
        print_preorder(tree->right);
    }

    printf("]");
}

char *insert_key(char *id) {
  sprintf(buffer, "%s@%s", top(scopes), id);
  insert(buffer, "", "", yylineno);
  return buffer;
}

void yyerror (char *msg) {
    fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
    exit(1);
}
