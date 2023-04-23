#include<stdio.h>
#define N 32

void swap(int[], int, int);
void print_array(int[], int);

void busort(int a[], int n)
{
  int i,j;
  int n2=n-1;

  for(i=1; i<n; i++){
    for(j=0; j<n2 ; j++){
      printf(".");
      if(a[j]>a[j+1]){
	swap(a,j,j+1);
      }
    }
    print_array(a,n);
    n2--;
  }
    
  return;
}

int main(void)
{
  int a1[] = {39, 16, 64, 8};
  int a2[] = {8, 7, 6, 5, 4, 3, 2, 1};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);
  
  print_array(a1,n1);
  busort(a1,n1);

  print_array(a2,n2);
  busort(a2,n2);
	
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

void swap(int a[], int m, int n)
{
  int tmp = a[m];
  a[m] = a[n];
  a[n] = tmp;

  return;
}
