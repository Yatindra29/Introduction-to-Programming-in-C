#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
struct rect_tag{
  int x;
  int y;
  int width;
  int height;
};
typedef struct rect_tag rectangle;
//Declare your rectangle structure here!


rectangle canonicalize(rectangle r) {
  if(r.width<0)
    {
      r.x=r.x + r.width;
      r.width= r.width * (-1);
    }
   if(r.height<0)
    {
      r.y=r.y +r.height;
      r.height=r.height * (-1);
    }//WRITE THIS FUNCTION
  return r;
}
rectangle xcheckmax(rectangle r1,rectangle r2)
{
  if(r1.x>r2.x)
    return r1;
  else
    return r2;
}
rectangle xcheckmin(rectangle r1, rectangle r2)
{
  if(r1.x<r2.x)
    return r1;
  else
  return r2;
}
rectangle ycheckmax(rectangle r1,rectangle r2)
{
  if(r1.y>r2.y)
    return r1;
  else
    return r2;
}
rectangle ycheckmin(rectangle r1,rectangle r2)
{
  if(r1.y<r2.y)
    return r1;
  else
    return r2;
}
rectangle intersection(rectangle r1, rectangle r2) {
  r1= canonicalize(r1);
  r2=canonicalize(r2);
  rectangle r;//WRITE THIS FUNCTION
  rectangle xmax=xcheckmax(r1,r2);
  rectangle xmin=xcheckmin(r1,r2);
  rectangle ymax=ycheckmax(r1,r2);
  rectangle ymin=ycheckmin(r1,r2);
  int differencex=xmax.x -xmin.x;
  int differencey=ymax.y-ymin.y;
  if(differencex<xmin.width && differencey<ymin.height)
    {
      r.x=xmax.x;
      r.y=ymax.y;
      if((xmax.x +xmax.width > xmin.x +xmin.width) ||( ymax.y +ymax.height > ymin.y+ ymin.height))
	{
	  r.width=xmin.width-(xmax.x-xmin.x);
	  r.height=ymin.height-(ymax.y-ymin.y);
	}
     else {
       r.width=xmax.width;
       r.height=ymax.height;
     }}
  else if(differencex>xmin.width || differencey>ymin.height)
    {
      r.width=0;
      r.height=0;
    }
  else if(differencex==xmin.width)
    {
      r.width=0;
      r.height=ymin.height-(ymax.y-ymin.y);
      r.x=max(r1.x ,r2.x);
      r.y=max(r1.y ,r2.y);
    }
  else if(differencey==ymin.height)
    {
      r.height=0;
      r.width=xmin.width-(xmax.x-xmin.x);
      r.x=max(r1.x, r2.x);
      r.y=max(r1.y, r2.y);
    }
	  return r;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
