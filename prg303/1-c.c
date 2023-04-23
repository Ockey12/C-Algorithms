#include<stdio.h>

int main(void)
{
  int a[] = {3, 7, 4, 1, 5, 9, 2, 6, 8, 0};
  int n, i;
	
  n = sizeof(a)/sizeof(a[0]);


  for(i=0; i<n; i++){
    if(a[i] <= 0){
      printf("Not all ");
      break;
    }
  }

  if(i == n){
    printf("ALL ");
  }

  
  printf("positive.\n");
  return 0;
}
