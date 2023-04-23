#include<stdio.h>

void print_array(int[], int);

int main(void)
{
  int w[] = {2, 5, 8, 9, 1, 3, 4, 7};
  int x[4];
  int n = sizeof(w)/sizeof(w[0]);
  int i, j, k, m;

  m = n / 2;

  for(i=0; i<m; i++){
    x[i]=w[i];
  }

  i=m;
  j=0;
  k=0;

  while(i<n && j<m){
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

  print_array(w, n);

  return 0;
}

void print_array(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++){
    printf("%d,", a[i]);
  }
  printf("\n");
  return;
}
