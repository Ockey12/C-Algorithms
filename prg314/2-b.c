#include<stdio.h>

#define N 32

void swap(int a[], int n, int m);
void print_array(int a[], int n);
void siftup(int h[], int start);
void insert(int h[], int size, int val);

void siftdown(int h[], int start, int size)
{
  int p,c;
  p = start;
  c = p*2+1;
  
  while(c < size){
    if((c+1)<size && h[c]>h[c+1]){
      c++;
    }

    if(h[p]<h[c]){
      return;
    }
    swap(h,p,c);
    p = c;
    c = p*2+1;
  }
  
  return;
}

int deletemin(int h[], int size)
{
  swap(h,0,size-1);
  siftdown(h,0,size-1);
  return h[size-1];
}

int main(void)
{
  int h[N] = {1,3,2,5,8,13,17,12,19,6};
  int size = 10;

  deletemin(h,size);
  size--;
  print_array(h,size);

  deletemin(h,size);
  size--;
  print_array(h,size);

  deletemin(h,size);
  size--;
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
