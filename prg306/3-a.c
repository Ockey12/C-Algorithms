#include<stdio.h>

int sorted(int a[], int n)
{
  if(n<2){
    return 1;
  }
  if(a[n-1]<a[n-2]){
    return 0;
  }

  return sorted(a, n-1);

}

int main(void)
{
  int a1[] = {1, 2, 5, 7, 8, 15};
  int n1 = sizeof(a1)/sizeof(a1[0]);

  int a2[] = {1, 2, 9, 7, 8, 15};
  int n2 = sizeof(a2)/sizeof(a2[0]);

  printf("%d\n",sorted(a1,n1));
  printf("%d\n",sorted(a2,n2));

  return 0;
}
