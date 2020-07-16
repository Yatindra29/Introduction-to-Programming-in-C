#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rotate(char matrix[10][10])
{
  char temp[10][10];
  int k=0;
  int i;
  int j;
  for(i=9;i>=0;i--)
    {
      for(j=0;j<10;j++)
	{
	  temp[j][k]=matrix[i][j];
	}
      k++;
    }
  i=0;
  j=0;
  for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	{
	  matrix[i][j]=temp[i][j];
	}}
  i=0;
  j=0;
  for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	{
	  printf("%c",matrix[i][j]);
	}
      printf("\n");
    }
}
int main(int argc,char ** argv){
  if(argc!=2){
    fprintf(stderr,"Invalid number of arguments");
  return EXIT_FAILURE;
  }
  FILE *f=fopen(argv[1],"r");
  if(f==NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  char matrix[10][10];
  char line[12];
  int x=0;
  while(fgets(line,12,f)!=NULL){
    if (strchr(line,'\n')==NULL){
      printf("Line is too long");
      return EXIT_FAILURE;
    }
    int count=0;
    for(int i=0;i<10;i++)
      {
	if(line[i]!='\0')
	  count++;
      }
    if(count<10){
      printf("Line is too short");
      return EXIT_FAILURE;
    }
    for(int j=0;j<10;j++)
      {
	matrix[x][j]=line[j];
      }
    x++;
  }
  rotate(matrix);
  return EXIT_SUCCESS;
}
