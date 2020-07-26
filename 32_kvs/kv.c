#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


char *get_key(char * text);
char *get_value(char *text);
kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *f=fopen(fname,"r");
  if(f==NULL){
    fprintf(stderr,"Failed to open file");
  }
  kvarray_t *to_return=malloc(sizeof(*to_return));
  (*to_return).arr=NULL;
  (*to_return).size=0;
  // kvpair_t *to_fill=malloc(sizeof(*to_fill));
  //(*to_fill).key=NULL;
  //(*to_fill).value=NULL;
  char *read;
  read=NULL;
  size_t sz=0;
  while(getline(&read,&sz,f)>=0){
    kvpair_t *to_fill=malloc(sizeof(*to_fill));
    ((*to_fill).key)=get_key(read);
    ((*to_fill).value)=get_value(read);
    (*to_return).arr=realloc((*to_return).arr,(((*to_return).size)+1)* sizeof(*to_fill));
    (*to_return).arr[(*to_return).size]=to_fill;
    (*to_return).size++;
    read=NULL;
    //(*to_fill).key=NULL;
    //(*to_fill).value=NULL;
  }
  free(read);
  if(fclose(f)!=0){
    perror("Failed to close the file");
  }
  return to_return;
}
char *get_key(char * text){
  char *to_return=NULL;
  int size=0;
  while(text[size]!='='){
    to_return=realloc(to_return, (size+1)*sizeof(*to_return));
    char c=text[size];
    to_return[size]=c;
    size++;
  }
  return to_return;
  // for(int i=0;i<size;i++){
  // free(to_return[i]);
  // }
  free(to_return);
}
char *get_value(char *text){
  char eq='=';
  char *ret;
  ret=strchr(text,eq);
  ret++;
  return ret;
}
void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t *curr;
  for(int i=0;i<(*pairs).size;i++){
  curr=(*pairs).arr[i];
  free((*curr).key);
  // free((*curr).value);
  free(curr);
   }
      // free((*pairs).arr[i]);
 free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t *curr;
  for(int i=0;i<(*pairs).size;i++){
    curr=(*pairs).arr[i];
    printf("key = '%s' value = '%s'\n", ((*curr).key), ((*curr).value));
  }}
char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t *curr;
  for(int i=0;i<(*pairs).size;i++){
    curr=(*pairs).arr[i];
    if(!(strcmp(key,(*curr).key)))
      return ((*curr).value);
  }
  return NULL;
}
