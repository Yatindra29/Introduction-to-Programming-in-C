#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//decrypt returns the value of key
//frequency_count returns the character with the highest frequency
int decrypt(FILE *f)
{
  int c;
  int letters[26];
  for(int z=0;z<26;z++)
    letters[z]=0;
  while(c=fgetc(f)!=EOF)
    {
      if(isalpha(c)){
	c=tolower(c);
	c-='a';
	letters[c]++;
      }}
  int max=0;
  int pos=0;
  for(int i=0;i<26;i++)
    {
      if(letters[i]>max)
	{
	  max=letters[i];
	  pos=i;
	}}
  int k=0;
  if(pos>=('e'-'a')) k=pos-('e'-'a');
  else
    k=(26-('e'-'a'))+pos;
  return k;
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
  
