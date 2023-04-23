#include<stdio.h>

int main(void)
{
  int a=100, b=200, c=10, d=500, e=8;
  int f, g, sum;
  double tmp, ave;

  sum=(a+b)*c-d;
  printf("%d\n", sum);

  f=sum/e;
  g=sum%e;
  printf("%d\n", f);
  printf("%d\n", g);

  tmp=sum;
  ave=tmp/e;
  printf("%f\n", ave);

  return 0;
}
