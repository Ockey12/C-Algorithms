#include<stdio.h>

void swap(int[], int, int);
void print_array(int[], int);

void pre_sort(int a[], int n)
{
  int i;

  for(i=0; i<n-1; i++){
    if(a[i]>a[i+1]){
      swap(a,i,i+1);
    }
    print_array(a,n);
  }
  
  return;
}

int main(void)
{
  int a1[] = {3,7,4,1,5,9,2,6};
  int a2[] = {64,-39,8,25};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);

  print_array(a1,n1);
  print_array(a2,n2);

  pre_sort(a1, n1);
  pre_sort(a2, n2);
	
  print_array(a1,n1);
  print_array(a2,n2);

  return 0;
}

void swap(int a[], int m, int n)
{
  int tmp;

  tmp = a[m];
  a[m] = a[n];
  a[n] = tmp;

  return;
}

void print_array(int a[], int n)
{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d,",a[i]);
  }
  printf("\n");

  return;
}
