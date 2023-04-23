#include<stdio.h>
#define N 16
int exp2under(int n);
void print_array(int a[], int n);

void sort(int w[], int left, int right)
{
  static int x[N];
  int i, j, k, m, n;

  n=right-left+1;
  m=n/2;

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


void msort(int a[], int n)
{
  int c=2;
  int tmp=0;

  while(c<=n){
    while(tmp<n-1){
      sort(a,tmp,tmp+c-1);
      tmp=tmp+c;
    }
    tmp=0;
    c*=2;
  }
}

int main(void)
{
  int a[] = {3, 1, 4, 7, 5, 2, 6, 8};
  int n = sizeof(a) / sizeof(a[0]);

  msort(a, n);
  print_array(a,n);
	
	
  return 0;
}

int exp2under(int n)
{
  int i;

  for (i = 2; i < n; i *= 2){
  }

  return i / 2;
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
