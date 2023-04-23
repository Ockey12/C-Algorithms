#include<stdio.h>

void print_array(int[], int);

void qsort(int a[], int n)
{
  int a1[16];
  int a2[16];
  int n1,n2,i,pivot;

  n1 = n2 = 0;
 
  pivot = a[n/2];

  for(i=0; i<n; i++){
    if(a[i]<pivot){
      a1[n1]=a[i];
      n1++;
    }else if(a[i]>pivot){
      a2[n2]=a[i];
      n2++;
    }
  }

  if(n1>0){
    qsort(a1,n1);
  }

  if(n2>0){
    qsort(a2,n2);
  }

  for(i=0; i<n1; i++){
    a[i]=a1[i];
  }

  a[i]=pivot;

  for(i=i+1; i<n1+1+n2; i++){
    a[i]=a2[i-n1-1];
  }

  return;
}

int main(void)
{
  int a[] = {3,1,4,7,5,9,2,6,8};
  int n = sizeof(a)/sizeof(a[0]);

  qsort(a,n);

  print_array(a,n);

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
