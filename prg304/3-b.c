#include<stdio.h>

void print_array(int[], int);

int main(void)
{
  int a1[16],a2[16],a3[16];
  int n1,n2,i,pivot;

  int a0[] = {3, 10, 4, 9, 5, 12, 7, 6, 8, 1, 11, 2};
  int n0 = sizeof(a0)/sizeof(a0[0]);

  print_array(a0,n0);

  pivot = a0[n0/2];

  n1 = 0;
  n2 = 0;

  for(i=0; i<n0; i++){
    if(a0[i]<pivot){
      a1[n1]=a0[i];
      n1++;
    }else if(a0[i]>pivot){
      a2[n2]=a0[i];
      n2++;
    }
  }

  print_array(a1,n1);
  print_array(a2,n2);

  for(i=0; i<n1; i++){
    a3[i]=a1[i];
  }

  a3[i]=pivot;

  for(i=i+1; i<n1+1+n2; i++){
    a3[i]=a2[i-n1-1];
  }

  print_array(a3,n0);

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

