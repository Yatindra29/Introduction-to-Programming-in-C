#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
int arg1(){
  char **to_be_sorted=NULL;
  char *Line=NULL;
  size_t size=0;
  int len=0;
  int i=0;
  while((len=getline(&Line,&size,stdin))>=0){
    to_be_sorted=realloc(to_be_sorted,(i+1)* sizeof(*to_be_sorted));
    to_be_sorted[i]=Line;
     Line=NULL;
    i++;
  }
  free(Line);
  sortData(to_be_sorted,i);
  for(int j=0;j<i;j++)
    {
      printf("%s",to_be_sorted[j]);
      free(to_be_sorted[j]);
     }
  free(to_be_sorted);
  return EXIT_SUCCESS;
}
int multiple_arguments(char **array_of_strings, int number_of_strings){
  char **to_be_sorted=NULL;
  char *line=NULL;
  size_t Size=0;
  int len=0;
  int j=0;
  for(int i=1;i<=number_of_strings;i++)
    {
      line=NULL;
      Size=0;
      len=0;
      j=0;
      FILE *f=fopen(array_of_strings[i],"r");
      if(f==NULL){
	fprintf(stderr,"Unable to open file");
	return EXIT_FAILURE;
      }
      else{
	while((len=getline(&line,&Size,f))>=0){
	  to_be_sorted=realloc(to_be_sorted,(i+1)* sizeof(*to_be_sorted));
	  to_be_sorted[j]=line;
	   line=NULL;
	  j++;
	}
	free(line);
	sortData(to_be_sorted,j);
	  for(int k=0;k<j;k++){
	    printf("%s",to_be_sorted[k]);
	    free(to_be_sorted[k]);
	  }}
      free(to_be_sorted);
      if(fclose(f)!=0){
	perror("Unable to close file");
	return EXIT_FAILURE;
      }
    }
  return EXIT_SUCCESS;
}
int main(int argc, char ** argv) {
  int ret=0;
  if(argc==0){
    fprintf(stderr,"No arguments given-Invalid");
    return EXIT_FAILURE;
  }
  else if(argc==1)
   ret= arg1();
  //WRITE YOUR CODE HERE!
  else if(argc>1)
    {
      int number_of_text_files=argc-1;
      ret=multiple_arguments(argv,number_of_text_files);
    }
  return ret;
}
