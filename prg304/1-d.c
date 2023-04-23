#include<stdio.h>

int main(void)
{
  int i,j;
  int a[] = {3,1,4,7,5,9,2,6,8};
  int n = sizeof(a)/sizeof(a[0]);
  
  for(i=n-1; i>0; i--){
    printf("%d:",i);

    for(j=0; j<i; j++){
      printf("%d-%d,",a[j],a[j+1]);
    }
    printf("\n");
  }

  return 0;
}
