#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t *ans;
  ans=createCounts();
  FILE *f=fopen(filename,"r");
  if(f==NULL)
  return NULL;
  char *line=NULL;
  size_t sz=0;
  while((getline(&line,&sz,f))>=0){
    char *n=strchr(line,'\n');
    if(n!=NULL)
      *n='\0';
    char *x=lookupValue(kvPairs, line);
    addCount(ans,x);
      }
  free(line);
  if(fclose(f)!=0){
    return NULL;
  }
  return ans;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc<2){
    fprintf(stderr,"Too few arguments");
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  // FILE *f=fopen(argv[1],"r");
  kvarray_t *kv;
  kv=readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for(int i=2;i<argc;i++){ 
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    counts_t *c=countFile(argv[i],kv);    //   (call this result c)
    if(c==NULL){
      return EXIT_FAILURE;
    }
    //compute the output file name from argv[i] (call this outName)
    char *outName=computeOutputFileName(argv[i]);
    FILE *f1=fopen(outName,"w");
    //open the file named by outName (call that f)
    printCounts(c,f1);
    //print the counts from c into the FILE f
    int res=fclose(f1);
    if(res!=0)
      return EXIT_FAILURE;
    //close f
    free(outName);
    freeCounts(c);
    //free the memory for outName and c
  }
  freeKVs(kv);
 //free the memory for kv
  return EXIT_SUCCESS;
}
