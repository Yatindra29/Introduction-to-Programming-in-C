#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n)
{
 long  int max=1;
  if(n==0)
    max=0;
  else
    {
 long  int count=0;
  for(long int i=0;i<n;i++)
    { count=0;
      for(long int j=i;j<n-1;j++)
	{
	  if(array[j]<array[j+1])
	    {
	      count++:
	    }}
	  if(count>max)
	    max=count;
    }
    }
  return max;
}
