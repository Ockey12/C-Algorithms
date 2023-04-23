#include<stdio.h>
#include<string.h>

int num_len(char* a[], int n, int t)
{
  int i, sum=0;

  for(i=0; i<n; i++){
    sum+=(strlen(a[i]) == t);
  }

  return sum;
}

int main(void)
{
  char* a[] = {"puma", "leopard", "cheetah", "caracal", "serval", "lion",
	       "cougar", "jaguar", "tiger", "panther", "cat", "ocelot", "lynx", "margay"};
  int n = sizeof(a)/sizeof(a[0]);
  int ans;

  ans = num_len(a, n, 6);

  printf("%d\n", ans);
  
  return 0;
}
