#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

void malloc_hashtable()
{
    int i;
    table = malloc(SIZE * sizeof(bucket *));
    for (i = 0; i < SIZE; i++)
        table[i] = NULL;
}

unsigned int hash(char *key)
{
    unsigned int hash = 5381;
    int c;
    while ((c = *key++) != 0)
        hash = ((hash << 5) + hash) + c;

    return hash % SIZE;
}

bucket *lookup(char *name)
{
    unsigned int hashval = hash(name);
    bucket *l = table[hashval];
    while ((l != NULL) && (strcmp(name, l->text) != 0))
        l = l->next;
    return l;
}

void insert(char *text, char *datatype, char *type, int linenumber)
{
    unsigned int index = hash(text);
    bucket *b = table[index];

    while ((b != NULL) && (strcmp(b->text, text) != 0))
        b = b->next;

    if (b == NULL)
    {
        b = (bucket *)malloc(sizeof(bucket));
        strcpy(b->text, text);
        strcpy(b->datatype, datatype);
        strcpy(b->type, type);
        b->lineslist = (linenumber_bucket *)malloc(sizeof(linenumber_bucket));
        b->lineslist->line = linenumber;
        b->lineslist->next = NULL;
        b->next = table[index];
        table[index] = b;
        // printf("Inserted %s for the first time with linenumber %d!\n", text, linenumber);
    }
    // else{
    //     fprintf(stderr, "A multiple declaration of variable %s at line %d\n", text, linenumber);
    //     exit(1);
    // }
}

void insert_linenumber(char *text, char *datatype, char *type, int linenumber)
{
    unsigned int index = hash(text);

    bucket *b = table[index];
    while ((b != NULL) && (strcmp(b->text, text) != 0))
        b = b->next;

    linenumber_bucket *t = b->lineslist;
    while (t->next != NULL)
        t = t->next;

    t->next = (linenumber_bucket *)malloc(sizeof(linenumber_bucket));
    t->next->line = linenumber;
    t->next->next = NULL;
    printf("Found %s again at line %d!\n", text, linenumber);
}

void print_symboltable()
{
    printf("\n");
    printf("Scope@Id   Datatype  Type      Line Numbers\n");
    printf("---------- -------- --------- -----------------\n");

    for (int i = 0; i < SIZE; ++i)
    {
        if (table[i] != NULL)
        {
            bucket *b = table[i];

            while (b != NULL)
            {
                linenumber_bucket *t = b->lineslist;
                printf("%-10s ", b->text);
                printf("%-8s ", b->datatype);
                printf("%-9s ", b->type);

                while (t != NULL)
                {
                    printf("%d ", t->line);
                    t = t->next;
                }

                printf("\n");
                b = b->next;
            }
        }
    }

    printf("\n");
}

void dump_symboltable(char *filename)
{
    printf("Generating '%s' symbol table log... ", filename);
    FILE *file = fopen(filename, "w");
    fprintf(file, "\n");
    fprintf(file, "Scope@Id   Datatype  Type          Line Numbers\n");
    fprintf(file, "---------- -------- ------------- -----------------\n");

    for (int i = 0; i < SIZE; ++i)
    {
        if (table[i] != NULL)
        {
            bucket *b = table[i];

            while (b != NULL)
            {
                linenumber_bucket *t = b->lineslist;
                fprintf(file, "%-10s ", b->text);
                fprintf(file, "%-8s ", b->datatype);
                fprintf(file, "%-14s ", b->type);

                while (t != NULL)
                {
                    fprintf(file, "%d ", t->line);
                    t = t->next;
                }

                fprintf(file, "\n");
                b = b->next;
            }
        }
    }

    fprintf(file, "\n");
    fclose(file);
    printf("Done\n");
}
