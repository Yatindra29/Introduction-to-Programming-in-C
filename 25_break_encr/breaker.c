#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//decrypt returns the value of key
//frequency_count returns the character with the highest frequency
char frequency_count(FILE *f)
{
  if(f==NULL)
    fprintf(stderr,"Invalid file opening");
  int c;
  int letters[26];
  for(int z=0;z<26;z++)
    letters[z]=0;
  while(c=fgetc(f)!=EOF)
    {
      if(isalpha(c)){
	c=tolower(c);
	letters[c-97]++;
      }}
  int max=0;
  char to_return=' ';
  for(int i=0;i<26;i++)
    {
      if(letters[i]>max)
	{
	  max=letters[i];
	  to_return=(char) (i+97);
	}}
  return to_return;
}
int decrypt(FILE *f)
{
  char repeat=frequency_count(f);
  int r=(int) repeat;
  char e='e';
  int asci=(int) e;
  int diff=r-asci;
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
  int key=-1;
  key=decrypt(f);
  if(key==-1)
    fprintf(stderr,"Invalid decryption \n");
  else
    printf("%d",key);
  return EXIT_SUCCESS;
}
  
