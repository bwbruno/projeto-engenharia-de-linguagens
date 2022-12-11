#define SIZE 200
#define SIZE_TEXT 100

typedef struct linenumber_bucket {
    int line;
    struct linenumber_bucket *next;
} linenumber_bucket;

typedef struct bucket {
    char text[SIZE_TEXT];
    char datatype[40];
    char type[40];
    linenumber_bucket *lineslist;
    struct bucket *next;
} bucket;

static struct bucket **table;

void malloc_hashtable();
unsigned int hash(char *s0);
bucket *lookup(char *text);
void insert(char *text, char *datatype, char *type, int linenumber);
void insert_linenumber(char *text, char *datatype, char *type, int linenumber);
void print_symboltable();
void dump_symboltable(char *filename);
