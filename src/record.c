#include "record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeRecord(record * r){
  if (r) {
    if (!r->code) free(r->code);
	  if (!r->opt1) free(r->opt1);
    free(r);
  }
}

record * createRecord(char * c1, char * c2){
  record * r = (record *) malloc(sizeof(record));

  if (!r) {
    printf("Allocation problem. Closing application...\n");
    exit(0);
  }

  r->code = strdup(c1);
  r->opt1 = strdup(c2);

  return r;
}

