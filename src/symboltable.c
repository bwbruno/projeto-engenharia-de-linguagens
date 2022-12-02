#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

int scope = 0;
int declaration;

void begin_scope() { scope++; }
void end_scope() { /* scope--; */ }

// Para verificar se alguma variável foi declarada mais de uma vez
void begin_declarations() { declaration = 1; }
void end_declarations() { declaration = 0; }

void malloc_hashtable(){
    int i; 
    table = malloc(SIZE * sizeof(bucket*));
    for(i = 0; i < SIZE; i++) table[i] = NULL;
}

unsigned int hash(char *key){
    unsigned int hash = 5381;
    int c;
    while ((c = *key++) != 0)
        hash = ((hash << 5) + hash) + c;

    return hash % SIZE;    
}

// Retorna NULL se não encontrar
bucket *lookup(char *name) {
    unsigned int hashval = hash(name);
    bucket *l = table[hashval];
    while ((l != NULL) && (strcmp(name,l->text) != 0)) l = l->next;
    return l;
}

void insert(char *text, char *datatype, char *type, int linenumber) {
    unsigned int index = hash(text);
    bucket* b = table[index];

    while ((b != NULL) && (strcmp(b->text, text) != 0)) b = b->next;

    // Se o text não existe na tabela, ele adiciona
    if(b == NULL) {
        b = (bucket*) malloc(sizeof(bucket));
        strcpy(b->text, text);
        strcpy(b->datatype, datatype);
        b->scope = scope;
        b->lineslist = (linenumber_bucket*) malloc(sizeof(linenumber_bucket));
        b->lineslist->line = linenumber;
        b->lineslist->next = NULL;
        b->next = table[index];
        table[index] = b; 
        // printf("Inserted %s for the first time with linenumber %d!\n", text, linenumber);
    } 
    else {
        // Se o text ja existe, adiciona a linha de onde ele foi invocado
		if(declaration == 0){
			linenumber_bucket *t = b->lineslist;
			while (t->next != NULL) t = t->next;
			
			t->next = (linenumber_bucket*) malloc(sizeof(linenumber_bucket));
			t->next->line = linenumber;
			t->next->next = NULL;
			// printf("Found %s again at line %d!\n", text, linenumber);
		}
		else{
            // Se text foi declarada duas vezes no mesmo escopo, informa o erro.
			if(b->scope == scope){
				fprintf(stderr, "A multiple declaration of variable %s at line %d\n", text, linenumber);
 				exit(1);
			}
            // Variável declarada com o mesmo nome mas em escopo diferente.
			else{
                b = (bucket*) malloc(sizeof(bucket));
                strcpy(b->text, text);
                strcpy(b->datatype, datatype);
                b->scope = scope;
                b->lineslist = (linenumber_bucket*) malloc(sizeof(linenumber_bucket));
                b->lineslist->line = linenumber;
                b->lineslist->next = NULL;

                b->next = table[index];
                table[index] = b; 
				// printf("Inserted %s for a new scope with linenumber %d!\n", text, linenumber);
			}	
		}		
	}
}

void pop(char *text) {
    int index = hash(text);
    table[index] = table[index]->next;
}

void dump_symboltable(FILE *file){  
  fprintf(file, "\n");
  fprintf(file, "Text       Dataype  Type      Scope  Line Numbers\n");
  fprintf(file, "---------- -------- --------- ------ -----------------\n");

  for (int i = 0; i < SIZE; ++i) { 
    if (table[i] != NULL) { 
        bucket *b = table[i];

        while (b != NULL) {
            linenumber_bucket *t = b->lineslist;
            fprintf(file, "%-10s ", b->text);
            fprintf(file, "%-8s ", b->datatype);
            fprintf(file, "%-9s ", b->type);
            fprintf(file, "%-5d  ", b->scope);

            while (t != NULL){
                fprintf(file, "%d ",t->line);
                t = t->next;
            }

            fprintf(file, "\n");
            b = b->next;
        }
    }
  }

  printf("\n");
}

