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
  int ch=fgetc(f);
  if(ch==EOF){
    fprintf(stderr,"Empty file");
    return EXIT_FAILURE;
  }
  char matrix[10][10];
  int row=0;
  int column=0;
  while(ch!=EOF){
    if(row>9){
      fprintf(stderr,"Extra rows");
      return EXIT_FAILURE;
    }
    if(column==10){
      column=0;
      row++;
      if(ch!='\n'){
	fprintf(stderr,"Line too long");
	return EXIT_FAILURE;
      }
    }
    else{
      if(ch=='\n'){
	fprintf(stderr,"Line too short");
	return EXIT_FAILURE;
      }
      matrix[row][column]=ch;
      column++;
    }
    ch=fgetc(f);
  }
  fclose(f);
  rotate(matrix);
  return EXIT_SUCCESS;
}
