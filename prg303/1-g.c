#include<stdio.h>

int bsearch(int a[], int n, int t)
{
  int head,tail,i;
  head = 0;
  tail = n-1;

  while(head <= tail){
    i = (head+tail) / 2;
    if(a[i] == t){
      return i;
    } else if (t < a[i]) {
      tail = i-1;
    } else {
      head = i+1;
    }
  }

  return -1;
}

int main(void)
{
  int a1[] = {15,16,17,20,25,29,31,33,37,45};
  int a2[] = {3,4,8,12};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);
  int ans;
	
  ans = bsearch(a1,n1,25);
  printf("%d\n",ans);
  ans = bsearch(a1,n1,31);
  printf("%d\n",ans);
  ans = bsearch(a1,n1,21);
  printf("%d\n",ans);
  ans = bsearch(a2,n2,3);
  printf("%d\n",ans);
  ans = bsearch(a2,n2,15);
  printf("%d\n",ans);

  return 0;
}
