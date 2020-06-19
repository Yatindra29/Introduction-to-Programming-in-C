#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);


int main(){
  int array1[]={1,2,3};
  if(maxSeq(NULL,0))
    { return EXIT_FAILURE; }
  if(maxSeq(array1,0))
    { return EXIT_FAILURE; }
  if(maxSeq(array1,3)!=3)
    { return EXIT_FAILURE;}
  int array2[]={5};
  if(maxSeq(array2,1)!=1)
    { return EXIT_FAILURE;}
  int array3[]={};
  if(maxSeq(array3,0)!=0)
    { exit(EXIT_FAILURE);}
  int array4[]={7,7,7,7};
  if(maxSeq(array4,4)!=1)
    {return EXIT_FAILURE;}
  int array5[]={5,3,1};
  if(maxSeq(array5,3)!=1)
    { return EXIT_FAILURE;}
  int array6[]={1,3,5,8,65,12,54,78};
  if(maxSeq(array6,8)!=5)
    { return EXIT_FAILURE;}
  int array7[]={1,4,4,6,6};
  if(maxSeq(array7,5)!=2)
    {return EXIT_FAILURE;}
  int array8[]={-32,20,13,35,48,23,1,618,16,14,36,43,85,1234,553,6464,-23,-22,-76,9,-90,8,1,23,45,19,34,10,51,29,73,17,23};
  if(maxSeq(array8,33)!=5)
    { return EXIT_FAILURE;}
  int array9[]={-3,-2,-1,0};
  if(maxSeq(array9,4)!=4)
    { return EXIT_FAILURE;} 
  // if(maxSeq(array10,n)!=3) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
