#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n)
{
 size_t max=1;
  if(n==0)
    max=0;
  else
    {
 size_t count=1;
  for(size_t i=0;i<n;i++)
    { count=1;
      for(size_t j=i;j<n;j++)
	{
	  if(array[j]<array[j+1])
	    {
	      count++;
	    }
	  else
	    {
	    break;
	    }}
	  if(count>max)
	    max=count;
    }
    }
  return max;
}
