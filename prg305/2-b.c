#include<stdio.h>

void print_array(int[], int);

void isort(int a[], int n){
  int tmp,i,j;

  for(i=1; i<n; i++){
    tmp=a[i];
    for(j=i; j>0; j--){
      if(a[j-1]<tmp){
        break;
      }
      a[j]=a[j-1];
    }
    a[j]=tmp;
    print_array(a,n);
  }

  return;
}

int main(void)
{
  int a1[] = {3, 7, 4, 1, 5, 9, 2, 6};
  int a2[] = {31, 59, 41, 26};
  int n1 = sizeof(a1) / sizeof(a1[0]);
  int n2 = sizeof(a2) / sizeof(a2[0]);

  print_array(a1, n1);
  isort(a1, n1);

  print_array(a2, n2);
  isort(a2, n2);

  print_array(a1, n1);
  print_array(a2, n2);

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
