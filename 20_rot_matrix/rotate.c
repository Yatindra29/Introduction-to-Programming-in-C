#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10])
{
  char temp;
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
	{
	  temp=matrix[i][j];
	  matrix[i][j]=matrix[j][i];
	  matrix[j][i]=temp;
	}}
}
