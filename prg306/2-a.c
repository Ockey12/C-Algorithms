#include<stdio.h>

void msort(int w[], int left, int right)
{
  static int x[16];
  int i, j, k, m, n;

  if(right-left+1<2){
    return;
  }

  n=right-left+1;
  m=n/2;

  msort(w, left, left+m-1);
  msort(w, left+m, right);

  for(i=0; i<m; i++){
    x[i]=w[left+i];
  }

  i=left+m;
  j=0;
  k=left;

  while(i<=right && j<m){
    if(w[i]<x[j]){
      w[k]=w[i];
      i++;
      k++;
    }else{
      w[k]=x[j];
      j++;
      k++;
    }
  }

  while(j<m){
    w[k]=x[j];
    j++;
    k++;
  }

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

int main(void)
{
  int a[] = {13, 11, 14, 17, 15, 19, 12, 16, 18};
  int n = sizeof(a)/sizeof(a[0]);

  msort(a, 0, n - 1);

  print_array(a,n);

  return 0;
}
