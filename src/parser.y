%{
#include "stack.c"
#include "symboltable.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"  
#define RED "\x1B[31m"  

int yylex(void);
void yyerror(char *s);
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern FILE *yyout;
extern char *fileStack;
extern char *fileSymbolTable;
extern struct stack *scopes;

char buffer[SIZE_TEXT];
struct node *parsetree;
int idScope = 1;
char auxScope[10];
char auxType[40];
int auxDimension=0;
int sizeList = 0;

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
char *get_symbol_datatype(char *id);
void *set_symbol_datatype(char *id, char *type);
int check_types_expr(char *type1, char *type2, char *operand);
int check_types_assign(char *type1, char *type2, char *id);
bucket *check_undeclared(char *id);
void check_declaration(char *id);
char *insert_key(char *id, char *type);
void print_help();

%}

%union {
    struct var_obj { 
        union Value *value;
        struct bucket *symbol;
        char name[100]; 
        struct node* nd;
    } nd_obj; 

    struct var_lit { 
        union Value *value;
        struct bucket *symbol;
        char name[100]; 
        char type[40];
        struct node* nd;
    } nd_lit; 
};

%token <nd_lit> STRING_LITERAL INT_NUMBER DOUBLE_NUMBER
%token <nd_obj> ID
%token <nd_obj> INT FLOAT DOUBLE STRING BOOL ENUM POINTER POINT_TO
%token <nd_obj> MAIN PROCEDURE FUNCTION RETURN
%token <nd_obj> WHILE DO IF ELSE FOR SWITCH CASE BREAK DEFAULT PRINT SCAN PRINT_ARRAY
%token <nd_obj> TRUE FALSE COMMA COLON SEMI_COLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT
%token <nd_obj> INCREMENT DECREMENT PLUS MINUS MULT DIVIDE MODULE ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIVIDE_ASSIGN MODULE_ASSIGN ASSIGN
%token <nd_obj> EQ NEQ LT LE GT GE AND OR NOT

%left PLUS MINUS
%left MULT DIVIDE MODULE
%left CAST

%type <nd_obj> prog decls_opt subprogrs decls decl dimen_op_opt decl_init_list pointer_decl dimen_ops dimen_op  pointer_type pointer_method assign_op subprog args_op stmt_list args arg stmt while_stmt if_stmt assign_stmt for_stmt switch_stmt inc_dec print_stmt scan_stmt func_args dimen_ind_op ind_op condition else_stmt_opt for_args comp_op switch_cases case logic_op c_term comp comp_term 
%type <nd_lit> expr_list expr num_expr ids procedure type function func_call return_stmt 

%start prog

//%type <sValue> stm

%%
prog : { push(scopes, "0"); } decls_opt subprogrs  
       {
            $$.nd = mknode($2.nd, $3.nd, "prog");
            parsetree = $$.nd;
            pop(scopes);
       }
       ;

decls_opt : decls  
            {
                $$.nd = mknode($1.nd, NULL, "decls-opt");
            }
            | { $$.nd = NULL; }
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
            $3.symbol = malloc(sizeof(struct bucket));
            //strcpy($3.symbol->type,$1.name);
            strcat($3.symbol->type,auxType);
            strcpy(auxType,"");
            // printf("Tipo de %s -> %s (auxType = ->%s<-)\n",$3.name, $3.symbol->type,auxType);
            $$.nd = mknode(temp, $3.nd, "ids");
       }
       | decl_init_list
       {
            strcpy(auxType,"");
            sizeList = 0;
            $$.nd = mknode($1.nd, NULL, "decl");
       }
       | pointer_decl
       {
            $$.nd = mknode($1.nd, NULL, "decl");
       }
       ;

decl_init_list : type LBRACK RBRACK ids SEMI_COLON
                 {
                    $3.symbol = malloc(sizeof(struct bucket));
                    strcpy($3.symbol->type,$1.name);
                    strcat($3.symbol->type,"[");
                    char tempSize[40];
                    sprintf(tempSize,"%d",sizeList);
                    strcat($3.symbol->type,tempSize);
                    strcat($3.symbol->type,"]");
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
                char temp[40] = "";
                strcat(temp,$1.name);
                strcat(temp,$2.name);
                strcat(temp,$3.name);
                strcat(auxType,temp);
                //printf("+1 DIMENSÃO\n");
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
          strcat(auxType,"[");
          char temp[40];
          sprintf(temp,"%d",sizeList);
          strcat(auxType,temp);
          strcat(auxType,"]");
          insert_key($1.name, "variable");
          $$.nd = mknode($2.nd, $4.nd, $1.name);
      }
      | ids COMMA ID assign_op expr
      {
          insert_key($3.name, "variable");
          char *id_type = get_symbol_datatype($3.name);
          check_types_assign(id_type, $5.type, $3.name);
          struct node *temp = mknode(NULL, NULL, $3.name);
	      struct node *tempDir = mknode(temp, $5.nd, $4.name);
          $$.nd = mknode($1.nd, tempDir, "comma");
      }
      | ID assign_op expr
      {
          insert_key($1.name, "variable");
          char *id_type = get_symbol_datatype($1.name);
          check_types_assign(id_type, $3.type, $1.name);
          struct node *temp = mknode(NULL, NULL, $1.name);
	      $$.nd = mknode(temp, $3.nd, $2.name);
      }
      | ids COMMA ID
      {
          insert_key($3.name, "variable");
          struct node *temp = mknode(NULL, NULL, $3.name);
	      $$.nd = mknode($1.nd, temp, "comma");
      }
      | ID
      {   
          insert_key($1.name, "variable");
          $$.nd = mknode(NULL, NULL, $1.name);
      }
      ;

expr_list : expr_list COMMA expr 
            {
                $$.nd = mknode($1.nd, $3.nd, "expr-list");
            }
            | expr                 
            {
                //printf("+1 INDICE");
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

procedure : PROCEDURE ID { insert_key($2.name, $1.name); sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++; } LPAREN args_op RPAREN LBRACE stmt_list RBRACE
            {
                pop(scopes);
                $$.nd = mknode($4.nd, $8.nd, $2.name);
            }
            ;

function : FUNCTION ID { insert_key($2.name, $1.name); sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++; } LPAREN args_op RPAREN COLON type LBRACE  stmt_list RBRACE
           {
                pop(scopes);
                set_symbol_datatype($2.name, $8.name);
                struct node *temp = mknode($5.nd, $11.nd, $2.name);
                $$.nd = mknode($8.nd, temp, "type");
           }
           | FUNCTION MAIN { insert_key($2.name, $1.name); sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++; } LPAREN args_op RPAREN COLON type LBRACE stmt_list RBRACE
           {
                pop(scopes);
                set_symbol_datatype($2.name, $8.name);
                struct node *temp = mknode($5.nd, $10.nd, $2.name);
                $$.nd = mknode($8.nd, temp, "type");
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
        //   printf("%sBug?? Arg Type idScope::%s %d\n", RED, RESET, idScope);
          insert_key($3.name, "variable");
          $$.nd = mknode($1.nd, $2.nd, $3.name);
      }
      | pointer_type ID  
      {
        //   printf("%sBug?? Arg Point idScope::%s %d\n", RED, RESET, idScope);
          insert_key($2.name, "variable");
          $$.nd = mknode($1.nd, NULL, $2.name);
      }
      ;

type : INT     { strcpy(auxType,$1.name); $$.nd = mknode(NULL, NULL, $1.name); }
     | DOUBLE  { strcpy(auxType,$1.name); $$.nd = mknode(NULL, NULL, $1.name); }
     | FLOAT   { strcpy(auxType,$1.name); $$.nd = mknode(NULL, NULL, $1.name); }
     | STRING  { strcpy(auxType,$1.name); $$.nd = mknode(NULL, NULL, $1.name); }
     | BOOL    { strcpy(auxType,$1.name); $$.nd = mknode(NULL, NULL, $1.name); }
     ;

stmt_list : stmt_list stmt 
            {
                $$.nd = mknode($1.nd, $2.nd, "stmt-list");
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
                strcpy($$.name, $1.name);
                char *id_type = get_symbol_datatype($1.name);
                strcpy($$.type, id_type);
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
                 char *id_type = get_symbol_datatype($1.name);
                 check_types_assign(id_type, $4.type, $1.name);
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
          sizeList++;
          strcpy($$.name, $1.name);
          char *id_type = get_symbol_datatype($1.name);
          strcpy($$.type, id_type);
          $$.nd = mknode($2.nd, NULL, $1.name);
       }
       | INT_NUMBER         
       {
          sizeList++;
          strcpy($$.name, $1.name);
          sprintf($$.type, "int");
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | DOUBLE_NUMBER      
       {
          sizeList++;
          strcpy($$.name, $1.name);
          sprintf($$.type, "double");
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | STRING_LITERAL     
       {
          sizeList++;
          strcpy($$.name, $1.name);
          sprintf($$.type, "string");
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | TRUE               
       {
          sizeList++;
          strcpy($$.name, $1.name);
          sprintf($$.type, "bool");
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | FALSE              
       {
          sizeList++;
          strcpy($$.name, $1.name);
          sprintf($$.type, "bool");
          $$.nd = mknode(NULL, NULL, $1.name);
       }
       | func_call
       {
          sizeList++;
          strcpy($$.name, $1.name);
          strcpy($$.type, $1.type);
          $$.nd = mknode($1.nd, NULL, "func-call");
       }
       | LPAREN expr RPAREN 
       {
          sizeList++;
          strcpy($$.name, $2.name);
          strcpy($$.type, $2.type);
          $$.nd = mknode($2.nd, NULL, "expr");
       }
       | expr PLUS expr     
       {
          sizeList++;
          check_types_expr($1.type, $3.type, $2.name);
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr MINUS expr    
       {
          sizeList++;
          check_types_expr($1.type, $3.type, $2.name);
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr MULT expr     
       {
          sizeList++;
          check_types_expr($1.type, $3.type, $2.name);
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr DIVIDE expr   
       {
          sizeList++;
          check_types_expr($1.type, $3.type, $2.name);
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | expr MODULE expr   
       {
          sizeList++;
          check_types_expr($1.type, $3.type, $2.name);
          $$.nd = mknode($1.nd, $3.nd, $2.name);
       }
       | LPAREN type RPAREN expr %prec CAST {}
       ;

num_expr : ID
           { 
                strcpy($$.name, $1.name);
                char *id_type = get_symbol_datatype($1.name);
                strcpy($$.type, id_type);
                $$.nd = mknode(NULL, NULL, $1.name);
           }
           | INT_NUMBER
           {
                strcpy($$.name, $1.name);
                sprintf($$.type, "int");
                $$.nd = mknode(NULL, NULL, $1.name);
           }
           | LPAREN num_expr RPAREN
           {
                strcpy($$.name, $2.name);
                strcpy($$.type, $2.type);
                $$.nd = mknode($2.nd, NULL, "num-expr");
           }
           | num_expr PLUS num_expr
           {
                check_types_expr($1.type, $3.type, $2.name);
                $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr MINUS num_expr
           {
                check_types_expr($1.type, $3.type, $2.name);
                $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr MULT num_expr
           {
                check_types_expr($1.type, $3.type, $2.name);
                $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr DIVIDE num_expr
           {
                check_types_expr($1.type, $3.type, $2.name);
                $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | num_expr MODULE num_expr
           {
                check_types_expr($1.type, $3.type, $2.name);
                $$.nd = mknode($1.nd, $3.nd, $2.name);
           }
           | LPAREN type RPAREN expr %prec CAST {}
           ; 

while_stmt : WHILE LPAREN condition RPAREN {sprintf(auxScope,"%d",idScope); push(scopes, auxScope); idScope++;} LBRACE stmt_list RBRACE {pop(scopes);}
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

for_args : assign_stmt SEMI_COLON ID comp_op ID SEMI_COLON inc_dec
         {
            check_undeclared($3.name); 
            check_undeclared($5.name); 
         }
         | decls ID comp_op ID SEMI_COLON inc_dec
         {
            check_undeclared($2.name); 
            check_undeclared($4.name); 
         }
         ;

inc_dec : ID INCREMENT { check_undeclared($1.name); }
        | ID DECREMENT { check_undeclared($1.name); }
        | INCREMENT ID { check_undeclared($2.name); }
        | DECREMENT ID { check_undeclared($2.name); }
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
          $$.nd = mknode($1.nd, $3.nd, $2.name);
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

    int c, hasInputOpt = 0, printParseTree = 0;
    while (1)
    {
        int option_index = 0;
        static struct option long_options[] = {
            {"input", required_argument, 0, 'i'},
            {"output", required_argument, 0, 'o'},
            {"dump-symboltable", required_argument, 0, 't'},
            {"dump-stack", required_argument, 0, 's'},
            {"print-parsetree", no_argument, 0, 'p'},
            {"help", no_argument, 0, 'h'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "t:s:o:i:ph", long_options, &option_index);
        if (c == -1) 
            break;

        switch (c) {
            case 'i':
                yyin = fopen(optarg, "r");
                yyparse();
                fclose(yyin);
                hasInputOpt = 1;
                break;

            case 'o':
                printf("option '%c' with value '%s'\n", c, optarg);
                break;

            case 't':
                fileSymbolTable = optarg;
                break;

            case 's':
                fileStack = optarg;
                dump_stack_init(fileStack);
                break;

            case 'p':
                printParseTree = 1;
                break;

            case 'h':
                print_help(argv[0]);
                break;

            case '?':
                printf("error! try \"%s --help\" for more information.\n", argv[0]);
                exit(0);
                break;

            default:
                printf("?? getopt returned character code 0%o ??\n", c);
            }
    }

    if(!hasInputOpt && optind < argc) {
      yyin = fopen(argv[optind++], "r");
      yyparse();
      fclose(yyin);
    }

    if(!hasInputOpt && argc == 1) {
         printf("%s: fatal error! no input files\n", argv[0]);
         exit(0);
    }

    if(fileSymbolTable) {
      dump_symboltable(fileSymbolTable);
    }

    if(printParseTree) {
      print_tree(parsetree);
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

struct bucket* mkbucket(){

}

void print_tree(struct node* tree) {
    printf("\nPrinting Preorder Parse Tree...\n");
    print_preorder(tree);
    printf("\n\nYou can see a visual representation of the parse tree. Copy and paste the result on the website: http://mshang.ca/syntree/\n");
}

void print_preorder(struct node *tree) {
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

char *get_symbol_datatype(char *id) {
    struct bucket *symbol = check_undeclared(id);
    return symbol->datatype;
}

void *set_symbol_datatype(char *id, char *type) {
    struct bucket *symbol = check_undeclared(id);
    strcpy(symbol->datatype, type);
}

int check_types_expr(char *type1, char *type2, char *operand) {

    if(!strcmp(type1, type2)) {
        return 1;
    }

    printf("%s%stype error:%s unsupported operand type for '%s': '%s' and '%s' at line %d\n", RED, BOLD, RESET, operand, type1, type2, yylineno);
    /* exit(0); */
    return 0;
}

int check_types_assign(char *type1, char *type2, char *id) {

    if(!strcmp(type1, type2)) {
        return 1;
    }

    printf("%s%stype error:%s '%s' is a %s object and does not suport '%s' assignment at line %d\n", RED, BOLD, RESET, id, type1, type2, yylineno);
    /* exit(0); */
    return 0;
}

bucket *check_undeclared(char *id) {
    
    struct bucket *symbol;
    struct stack_bucket *sb = scopes->head;

    // Se não encontra no escopo atual, busca no próximo
    while (sb != NULL)
    {
        sprintf(buffer, "%s@%s", sb->text, id);
        symbol = lookup(buffer);
        if(symbol == NULL) {
            sb = sb->next;
        } else {
            break;
        }
    }

    if(symbol == NULL) {
        printf("%s%serror:%s '%s' undeclared at line %d\n", RED, BOLD, RESET, id, yylineno);
        exit(0);
    }     
    return symbol;
}

void check_declaration(char *id) {
    bucket *symbol = lookup(id);

    char * string = strdup(id);
    char * token = strtok(string, "@");
    token = strtok(NULL, "@");

    if(symbol != NULL) {
        printf("%s%serror:%s multiple declaration of '%s' at line %d\n", RED, BOLD, RESET, token, yylineno);
        /* exit(0); */
    }     
}

char *insert_key(char *id, char *type) {
    sprintf(buffer, "%s@%s", top(scopes), id);
    check_declaration(buffer);
    insert(buffer, auxType, type, yylineno);
    return buffer;
}

void yyerror(char *msg) {
    fprintf (stderr, "%s%s%s:%s '%s' at line %d\n", RED, BOLD, msg, RESET, yytext, yylineno);
    exit(1);
}

void print_help(char *compilername) {
    printf("\n%sUSAGE%s\n", BOLD, RESET);
    printf("\t%s%s%s INPUTFILE OUTPUTFILE [OPTION]...\n\n", BOLD, compilername, RESET);
    printf("%sOPTIONS%s\n", BOLD, RESET);
    printf("\tRequired arguments to long options are mandatory for short options too.\n\n");
    printf("\t%s-i, --input=%sFILE\n", BOLD, RESET);
    printf("\t\tsimple++ source code that must be processed\n\n");
    printf("\t%s-o, --output=%sFILE\n", BOLD, RESET);
    printf("\t\tfunctional program file in simplified c that will be generated\n\n");
    printf("\t%s-t, --dump-symboltable=%sFILE\n", BOLD, RESET);
    printf("\t\tat the end of parsing, generates an log file which is a snapshot of the symbol table\n\n");
    printf("\t%s-s, --dump-stack=%sFILE\n", BOLD, RESET);
    printf("\t\twhile parsing, generates and update an log file with the state of the scope stack for each line of parsed code\n\n");
    printf("\t%s-p, --print-parsetree%s\n", BOLD, RESET);
    printf("\t\tdisplay the syntax tree of the analyzed code in preorder\n\n");
    printf("\t%s-h, --help%s\n", BOLD, RESET);
    printf("\t\tdisplay this help and exit\n\n");
    exit(1);
}

