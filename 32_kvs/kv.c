#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


char *get_key(char * text);
char *get_value(char *text);
kvpair_t *to_ret(char *text);
 kvpair_t *to_ret(char *text){
 kvpair_t *t;
 t=malloc(sizeof(*t));
 (*t).key=get_key(text);
 (*t).value=get_value(text);
 return t;
 free(t);
}
kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *f=fopen(fname,"r");
  if(f==NULL){
    fprintf(stderr,"Failed to open file");
  }
  kvarray_t *to_return=malloc(sizeof(*to_return));
  (*to_return).clear=NULL;
  (*to_return).arr=NULL;
  (*to_return).size=0;
  char *read;
  read=NULL;
  size_t sz=0;
   kvpair_t *to_fill=NULL;
  while(getline(&read,&sz,f)>=0){
     to_fill=to_ret(read);
     ((*to_return).arr)=realloc(((*to_return).arr),(((*to_return).size)+1) * sizeof((*to_return).arr));
    (*to_return).arr[(*to_return).size]=to_fill;
    ((*to_return).clear)=realloc(((*to_return).clear),(((*to_return).size)+1) * sizeof((*to_return).clear));
    ((*to_return).clear)[(*to_return).size]=read;
    ((*to_return).size)++;
    // free(read);
      read=NULL;
  }
  free(read);
  read=NULL;
  int res=fclose(f);
  if(res!=0){
    perror("Failed to close the file");
    return NULL;
  }
  return to_return;
  free(to_return);
}
char *get_key(char * text){
  char *to_return=NULL;
  int size=0;
  while(text[size]!='='){
    to_return=realloc(to_return, (size+1)*sizeof(to_return));
    char c=text[size];
    to_return[size]=c;
    size++;
  }
  to_return=realloc(to_return, (size+1)*sizeof(to_return));
  to_return[size]='\0';
  return to_return;
   free(to_return);
}
char *get_value(char *text){
  char eq='=';
  char *ret;
  ret=strchr(text,eq);
  ret++;
  char* n = strchr(text, '\n');
  if (n != NULL) *n = '\0';
  return ret;
}
void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<(*pairs).size;i++){
    free(pairs -> clear[i]);
     free(pairs -> arr[i] -> key);
    free(pairs -> arr[i]);
  }
  free(pairs -> clear);
  free(pairs -> arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t *curr=NULL;
  for(int i=0;i<(*pairs).size;i++){
    curr=pairs -> arr[i];
    printf("key = '%s' value = '%s'\n", curr -> key, curr -> value);
  }}
char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t *curr;
  for(int i=0;i<(*pairs).size;i++){
    curr=pairs -> arr[i];
    if(!(strcmp(curr -> key,key)))
      return (curr -> value);
  }
  return NULL;
}
