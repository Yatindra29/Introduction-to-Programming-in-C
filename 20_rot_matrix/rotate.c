#include <stdio.h>
#include <stdlib.h>

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
      for(int j=0;j<10;j++)
	{
	  matrix[i][j]=temp[i][j];
	}}
}
