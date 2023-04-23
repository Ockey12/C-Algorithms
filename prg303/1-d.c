#include<stdio.h>

int all_even(int a[], int n)
{
  int i;

  for(i=0; i<n; i++){
    if(a[i]%2 != 0){
      return 0;
    }
  }

  return 1;

}


int main(void)
{
  int a1[] = {14, 18, 4, 12, 16, 18, 2, 6, 8};
  int a2[] = {14, 18, 4, 12, 16, 7, 6, 8};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);

  int ans1 = all_even(a1, n1);
  int ans2 = all_even(a2, n2);

  printf("%d,%d\n", ans1, ans2);
	
  return 0;
}
