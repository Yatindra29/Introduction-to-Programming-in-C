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
  char letters[1000];
  int j=0;
  while(c=fgetc(f)!=EOF)
    {
      if(isalpha(c)){
	c=tolower(c);
      char ch=(char) c;
      letters[j]=ch;
      j++;
      }}
  int u=j;
  int max=0;
  int pos=0;
  int count=0;
  for(int i=0;i<u;i++)
    {
      for(int k=0;k<u;k++)
	{
	  if(letters[i]==letters[k])
	    count++;
	}
      if(count>max}
      {
	max=count;
	pos=i;
      }}
  return letters[pos];
}
int decrypt(FILE *f)
{
  char repeat=frequency_count(f);
  int r=(int) repeat;
  char e='e';
  int asci=(int) e;
  int diff=r-e;
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
  
