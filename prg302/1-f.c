#include<stdio.h>

  /* ここにeleven()とtriple()を書く */
int eleven(void)
{
  return 11;
}

int triple(int n)
{
  return n*3;
}

int main(void)
{
  int n0,n1,n2,n3;

  n0 = eleven();
  n1 = eleven();
  n2 = triple(7);
  n3 = triple(11);

  printf("%d,%d,%d,%d\n",n0,n1,n2,n3);

  return 0;
}
