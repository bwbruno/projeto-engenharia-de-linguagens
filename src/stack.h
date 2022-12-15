#include <stdlib.h>
#include <string.h>

struct stack_bucket
{
    char *text;
    struct stack_bucket *next;
};

struct stack
{
    struct stack_bucket *head;
};

struct stack *malloc_stack();
void push(struct stack *s, char *value);
char *top(struct stack *s);
void pop(struct stack *s);
void print_stack(struct stack *s);
void dump_stack_init(char *filename);
void dump_stack(struct stack *s, char *filename, int line);