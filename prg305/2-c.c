#include<stdio.h>

int golden(int n)
{
  int ans1, ans2; 

  if(n==0){
    return 0;
  }

  if(n==1){
    return 1;
  }

  ans1=golden(n-1);
  ans2=golden(n-2);

  return ans1+ans2;

}

int main(void)
{
  int n0, n1, n2, n3;

  n0 = golden(0);
  n1 = golden(1);
  n2 = golden(7);
  n3 = golden(14);

  printf("%d,%d,%d,%d\n", n0, n1, n2, n3);

  return 0;
}
