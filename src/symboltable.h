#define SIZE 109

void begin_scope();
void end_scope();
void begin_declarations();
void end_declarations();

typedef struct linenumber_bucket {
    int line;
    struct linenumber_bucket *next;
} linenumber_bucket;

typedef struct bucket {
    char text[50];
    char datatype[20];
    char type[20];
    int scope;
    linenumber_bucket *lineslist;
    struct bucket *next;
} bucket;


static struct bucket **table;

void malloc_hashtable();

unsigned int hash(char *s0);

bucket *lookup(char *text);

void insert(char *text, char *datatype, char *type, int linenumber);

void pop(char *text);

void dump_symboltable(FILE *file);