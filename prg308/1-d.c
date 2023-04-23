#include<stdio.h>
#include<string.h>

char* lsearch(char* a[], int n, int t)
{
  int i;

  for (i = 0; i < n; i++) {
    if (strlen(a[i]) == t) {
      return a[i];
    }
  }

  return NULL;
}

int main(void)
{
  char* ans;
  char* a[] = {"gerbil", "ox", "tiger", "hare", "ouroboros", "serpent",
               "stallion", "ewe", "chimpanzee", "hummingbird"};
  int n = sizeof(a) / sizeof(a[0]);
  
  ans = lsearch(a, n, 7);
  if (ans != NULL) {
    printf("%s\n", ans);
  } else {
    printf("Not found.\n");
  }
  
  ans = lsearch(a, n, 12);
  if (ans != NULL) {
    printf("%s\n", ans);
  } else {
    printf("Not found.\n");
  }

  return 0;
}
