#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;
double compute(retire_info r, double balance,int starting_age)
{
  int age;
  int month;
  double d;
  double c;
  for(int i=1;i<=r.months;i++)
    {
      age=starting_age/12;
      month=starting_age%12;
      c=(balance* r.rate_of_return)/(100*12);
      d=balance+c+r.contribution;
  printf("Age %3d month %2d you have $%.2lf\n", age,month,d);
  balance=d;
  starting_age++;
}
  return d;
}
void retirement(int startAge, double initial, retire_info working,retire_info retired)
{
  int r_age=startAge+1;
 double balance1= compute(working, initial,r_age);
  int req=startAge+working.months+1;
  retired.months=retired.months-1;
 double balance2=compute(retired,balance1,req);
 if(balance2<0)
   printf("balance2");
}
int main(void){
  retire_info Working;
  Working.months=489;
  Working.contribution=1000.00;
  Working.rate_of_return=4.5;
  retire_info Retired;
  Retired.months=384;
  Retired.contribution=-4000.00;
  Retired.rate_of_return=1.00;
  double savings=21345.00;
  int st_age=327;
  int pr_age=st_age/12;
  int pr_month=st_age%12;
  printf("Age %3d month %2d you have $%.2lf\n", pr_age,pr_month,savings);
  retirement(st_age,savings,Working,Retired);
  return EXIT_SUCCESS;
}
