#include<stdio.h>

void print_array(int[], int);

void right_shift(int a[], int n)
{
  int i, tmp;

  tmp=a[n-1];

  for(i=n-1; i>0; i--){
    if(a[i-1]<tmp){
      break;
    }
    a[i]=a[i-1];
  }

  a[i]=tmp;

  return;
}

int main(void)
{
  int a1[] = {21,22,23,25,26,27,28,24};
  int a2[] = {2,3,4,5,6,7,8,9,10,11,12,1};
  int a3[] = {101,102,103,104};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);
  int n3 = sizeof(a3)/sizeof(a3[0]);

  print_array(a1,n1);
  right_shift(a1,n1);
  print_array(a1,n1);

  print_array(a2,n2);
  right_shift(a2,n2);
  print_array(a2,n2);

  print_array(a3,n3);
  right_shift(a3,n3);
  print_array(a3,n3);

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
