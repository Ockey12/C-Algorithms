#include<stdio.h>

void swap(int[], int, int);
void print_array(int[], int);

void qsort(int a[], int left, int right)
{
  int pivot,i,j;

  if(left==right){
    return;
  }

  pivot=a[(left+right)/2];

  i=left;
  j=right;

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

    swap(a,i,j);

    i++;
    j--;

  }

  qsort(a, left, i-1);
  qsort(a, j+1, right);

  return;
}

int main(void)
{
  int a[] = {13, 11, 14, 17, 15, 19, 12, 16, 18};
  int n = sizeof(a) / sizeof(a[0]);

  qsort(a, 0, n - 1);
  print_array(a, n);
	
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
    printf("%d,", a[i]);
  }
  printf("\n");

  return;
}
