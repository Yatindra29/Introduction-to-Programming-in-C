#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);
int main(){
  unsigned res1=power(10,0);
  if(res1!=1)
    exit(EXIT_FAILURE);
  unsigned res2=power(0,3);
  if(res2!=0)
    exit(EXIT_FAILURE);
  unsigned res3=power(10,6);
  if(res3!=1000000)
  exit(EXIT_FAILURE);
  unsigned res4=power(3,2);
  if(res4!=9)
    exit(EXIT_FAILURE);
  unsigned res5=power(0,0);
  if(res5!=1)
    exit(EXIT_FAILURE);
  unsigned res6=power(-3,2);
  if(res6!=9)
    exit(EXIT_FAILURE);
  exit(EXIT_SUCCESS);
}

