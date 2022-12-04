#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

struct stack *malloc_stack()
{
    struct stack *stack = malloc(sizeof *stack);

    if (stack)
    {
        stack->head = NULL;
    }
    return stack;
}

void push(struct stack *s, char *value)
{
    struct stack_bucket *sb = malloc(sizeof *sb);

    if (sb)
    {
        char *temp = malloc(strlen(value) + 1);
        if (temp) strcpy(temp, value);
        sb->text = temp;
        sb->next = s->head;
        s->head = sb;
    }
}

char *top(struct stack *s)
{
    if (s && s->head)
    {
        return s->head->text;
    }
    else
    {
        return NULL;
    }
}

void pop(struct stack *s)
{
    if (s->head != NULL)
    {
        struct stack_bucket *tmp = s->head;
        s->head = s->head->next;
        free(tmp->text);
        free(tmp);
    }
}

void print_stack(struct stack *s)
{
    printf("\n");
    printf("Stack\n");
    printf("--------------------\n");
    
    struct stack_bucket *sb = s->head;

    while (sb != NULL)
    {
        printf("%-20s\n", sb->text);
        sb = sb->next;
    }
}