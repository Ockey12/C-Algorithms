#include<stdio.h>

int sigma(int n)
{

  if(n==0){
    return 0;
  }

  return n+sigma(n-1);

}

int main(void)
{
  int n0, n1;

  n0 = sigma(10);
  n1 = sigma(0);

  printf("%d,%d\n",n0,n1);

  return 0;
}
