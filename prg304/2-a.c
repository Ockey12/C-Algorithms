#include<stdio.h>

void swap(int[], int, int);
void print_array(int[], int);
int max_index(int[], int);

void ssort(int a[], int n)
{
  int i, idx;

  for(i=n-1; i>0; i--){
    idx=max_index(a,i);
    swap(a,idx,i);
    print_array(a,n);
  }

  return;
	
}

int main(void)
{
  int a1[] = {8, 9, 2, 3, 4, 5, 6, 7, 1};
  int a2[] = {46, 21, 91, 38};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);

  print_array(a1,n1);
  ssort(a1, n1);
  
  print_array(a2,n2);
  ssort(a2, n2);
  
  return 0;
}

int max_index(int a[], int n)
{
  int i, maxidx = 0;

   for(i=1; i<=n; i++){
      if(a[maxidx]<a[i]){
	maxidx=i;
      }
    }

  return maxidx;
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
