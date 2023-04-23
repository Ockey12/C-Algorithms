#include<stdio.h>

#define N 32

void swap(int a[], int n, int m);
void print_array(int a[], int n);

void siftup(int h[], int start)
{
  int c = start;
  int p = (c-1)/2;
  while(c>0){
    if(h[p]<h[c]){
      return;
    }
    swap(h,c,p);
    c = p;
    p = (c-1)/2;
  }
  return;
}

void insert(int h[], int size, int val)
{
  h[size] = val;
  siftup(h,size);
  return;
}

int main(void)
{
  int h[N] = {2,5,3,12,10,13,7};
  int size = 7;

  insert(h,size,8);
  size++;
  print_array(h,size);
  
  insert(h,size,19);
  size++;
  print_array(h,size);
  
  insert(h,size,1);
  size++;
  print_array(h,size);

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
