#include<stdio.h>

#define N 32

void swap(int a[], int n, int m);
void print_array(int a[], int n);

void siftdown(int h[], int start, int size)
{
  int p,c;
  p = start;
  c = p*2+1;
  
  while(c < size){
    if((c+1)<size && h[c]<h[c+1]){
      c++;
    }

    if(h[p]>h[c]){
      return;
    }
    swap(h,p,c);
    p = c;
    c = p*2+1;
  }
  
  return;
}

void heapify(int h[], int size)
{
  int p=(size-2)/2;

  while(p>=0){
    siftdown(h,p,size);
    p--;
  }
  
  return;
}

int deletemin(int h[], int size)
{
  swap(h,0,size-1);
  siftdown(h,0,size-1);
  return h[size-1];
}

void heapsort(int h[], int size)
{
  int s=size,i;
  
  heapify(h,size);

  for(i=0; i<size; i++){
    deletemin(h,s);
    s--;
  }

  return;
}

int main(void)
{
  int a[N] = {3,10,4,7,15,9,2,6,8};
  int n = 9;
  
  print_array(a,n);
  
  heapsort(a,n);
  
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
