#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//decrypt returns the value of key
//frequency_count returns the character with the highest frequency
int decrypt(FILE *f)
{
  char c;
  int letters[26];
  for(int z=0;z<26;z++)
    letters[z]=0;
  while(c=fgetc(f)!=EOF)
    {
      if(isalpha(c)){
	c=tolower(c);
	c-='a';
	int ch=(int) c;
	letters[ch]++;
      }}
  int max=0;
  int pos=-1;
  for(int i=0;i<26;i++)
    {
      if(letters[i]>max)
	{
	  max=letters[i];
	  pos=i;
	}}
  int r=pos;
  char e='e';
  int asci=(int) e;
  int diff=r-asci+97;
  if(diff<0)
  diff+=26;
  return diff;
}
int main(int argc, char ** argv){
  if(argc!=2){
    fprintf(stderr,"Invalid number of arguments \n");
    return EXIT_FAILURE;
  }
  FILE *f=fopen(argv[1],"r");
  if(f==NULL){
    fprintf(stderr,"Can't open file \n");
    return EXIT_FAILURE;
  }
  else{
  int key=decrypt(f);
    printf("%d",key);
  if(fclose(f)!=0){
    perror("Failed to close the input file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
  }}
  
