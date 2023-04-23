#include<stdio.h>

int sum(int m, int n)
{
  int max, min;

  if(m>n){
    max=m;
    min=n;
  }else if(m<n){
    max=n;
    min=m;
  }else{
    return m;
  }

  return max+sum(max-1, min);

}

int main(void)
{
  int n0,n1,n2,n3;

  n0 = sum(5,9);
  n1 = sum(4,-1);
  n2 = sum(-3,3);
  n3 = sum(5,5);

  printf("%d,%d,%d,%d\n",n0,n1,n2,n3);

  return 0;
}
