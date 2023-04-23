#include<stdio.h>

int max5(int n0, int n1, int n2, int n3, int n4)
{

  int a[] = {n1, n2, n3, n4};
  int i, max=n0;

  for(i=0; i<4; i++){
    if(max < a[i]){
      max = a[i];
    }
  }

  return max;

}

int main(void)
{
  int n0,n1,n2,n3,n4,n5;

  n0 = max5(-1,-2,-3,-4,-5);
  n1 = max5(-6,-2,-3,-4,-5);
  n2 = max5(-6,-7,-3,-4,-5);
  n3 = max5(-6,-7,-8,-4,-5);
  n4 = max5(-6,-7,-8,-9,-5);
  n5 = max5(10,10,10,10,10);

  printf("%d,%d,%d,%d,%d,%d\n",n0,n1,n2,n3,n4,n5);

  return 0;
}
