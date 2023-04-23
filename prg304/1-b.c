#include<stdio.h>

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

int main(void)
{
  int a[] = {3,7,4,1,5,9,2,6,8};
  int ans;

  ans = max_index(a,4);
  printf("%d\n",a[ans]);

  ans = max_index(a,5);
  printf("%d\n",a[ans]);

  return 0;
}
