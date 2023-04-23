#include<stdio.h>

int main(void)
{
  int a[]={3, -7, 4, 1, -5, -9, 0, -2, 6, -8};
  int n=10;
  int i;

  for(i=0; i<n; i++){
    if(a[i]>0){
      printf("%d is positive.\n", a[i]);
    }else{
      printf("Not positive (%d).\n", a[i]);
    }
  }

  return 0;
}
