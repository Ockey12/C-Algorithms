#include<stdio.h>

void swap(int[], int, int);
void print_array(int[], int);

int main(void)
{
  int i, j, pivot;
  int dummy[4] = {0};
  int a[] = {1, 2, 3, 5, 6, 7, 8, 4};
  int n = sizeof(a) / sizeof(a[0]);

  int tmp;

  pivot = a[n / 2];
  printf("%d\n",pivot);

  i = 0;
  j = n - 1;

  while (1){
    while (a[i] < pivot){
      i++;
    }

    while (a[j] > pivot){
      j--;
    }

    if(i>=j){
      break;
    }

    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;

    i++;
    j--;

  }

  printf("%d\n", dummy[0]);
  print_array(a,n);

  return 0;
}

void swap(int a[], int n, int m)
{
  int tmp;
  tmp = a[n];
  a[n] = a[m];
  a[m] = tmp;

  return;
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
