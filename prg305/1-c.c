#include<stdio.h>
#include<string.h>

int bsearch(char* a[], int n, char t[])
{

  int head,tail,i;
  head=0;
  tail=n-1;

  while(head<=tail){
    i=(head+tail)/2;
    if(strcmp(a[i],t)==0){
      return i;
    }else if(strcmp(a[i],t)>0){
      tail=i-1;
    }else{
      head=i+1;
    }
  }

  return -1;
  
}

int main(void)
{
  char* a[] = {"chimpanzee", "ewe", "gerbil", "hare", "hummingbird",
	       "ouroboros", "ox", "serpent", "stallion", "tiger"};
  int n = sizeof(a)/sizeof(a[0]);
  int ans1, ans2, ans3, ans4, ans5, ans6;
  char str1[] = "ape";
  char str2[] = "chimpanzee";
  char str3[] = "gerbil";
  char str4[] = "mouse";
  char str5[] = "tiger";
  char str6[] = "zebra";
  
  ans1 = bsearch(a, n, str1);
  ans2 = bsearch(a, n, str2);
  ans3 = bsearch(a, n, str3);
  ans4 = bsearch(a, n, str4);
  ans5 = bsearch(a, n, str5);
  ans6 = bsearch(a, n, str6);

  printf("%d,%d,%d,%d,%d,%d\n", ans1, ans2, ans3, ans4, ans5, ans6);
  
  return 0;
}
