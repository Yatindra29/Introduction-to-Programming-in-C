#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *to_return;
  to_return=malloc(sizeof(*to_return));
  (*to_return).arr=NULL;
  (*to_return).size=0;
  (*to_return).count_unknown=0;
  return to_return;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name==NULL){
    c->count_unknown++;
  }
  
  else{
    int i=0;
    int flag=0;
  for(i=0;i<(*c).size;i++){
    if(!(strcmp(c->arr[i] ->str,name))){
      c->arr[i] -> count++;
      flag=1;
    }
  }
  if(flag!=1){
    (*c).arr=realloc((*c).arr, ((c->size)+1) *sizeof((*c).arr));
    one_count_t *con;
    con=malloc(sizeof(*con));
    (*con).str=malloc(sizeof(strlen(name)+2));
    strcpy(con->str,name);
    (*con).count=1;
    (*c).arr[i]=con;
    c->size++;
  }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i=0;i<(*c).size;i++){
    fprintf(outFile,"%s:%d\n", c->arr[i]->str,c->arr[i]->count); 
  }
  if(c->count_unknown !=0){
    fprintf(outFile,"<unknown>:%d", c->count_unknown);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int i=0;i<c->size;i++){
     free(c->arr[i]->str);
    free(c->arr[i]);
}
  free(c->arr);
  free(c);
}
