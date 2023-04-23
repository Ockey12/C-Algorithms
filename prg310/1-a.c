#include<stdio.h>

#define M 16

void print_array(int[],int);

int main(void)
{
  int bucket[M] = {0};
  int a[] = {12, 3, 15, 7, 1, 13};
  int n = sizeof(a)/sizeof(a[0]);
  int i;

  for(i = 0; i < n; i++){
    printf("%d\n", a[i]);
    bucket[a[i]]=a[i];
  }

  print_array(bucket,M);

  for(i = 0; i < M; i++){ 
    if(bucket[i]!=0){
      printf("%d,",bucket[i]);
    }
  }
  printf("\n");
  
  return 0;
}

void print_array(int a[], int n)
{
  int i;
  for(i = 0; i < n; i++){
    printf("%d,",a[i]);
  }
  printf("\n");
  return;
}
