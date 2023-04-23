#include<stdio.h>
#include<string.h>

int lsearch(char* a[], int n, char t[])
{
  int i;

  for(i=0; i<n; i++){
    if(strcmp(a[i],t)==0){
      return i;
    }
  }

  return -1;

}


int main(void)
{
  char* a[] = {"gerbil", "ox", "tiger", "hare", "ouroboros", "serpent",
	       "stallion", "ewe", "chimpanzee", "hummingbird"};
  int n = sizeof(a)/sizeof(a[0]);
  int ans1, ans2;
  char t1[] = "horse";
  char t2[] = "stallion";
	
  ans1 = lsearch(a, n, t1);
  ans2 = lsearch(a, n, t2);
	
  printf("%d, %d\n", ans1, ans2);
	
  return 0;
}
