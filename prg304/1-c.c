#include<stdio.h>
#include<string.h>

void show_len(char* a[], int n)
{
  int i, l;

  for(i=0; i<n; i++){
    l=strlen(a[i]);
    printf("%d:%s\n",l,a[i]);
  }
  
  return;
}

int main(void)
{
  char* a1[] = {"gerbil", "ox", "tiger", "hare", "ouroboros", "serpent"};
  char* a2[] = {"stallion", "ewe", "chimpanzee", "hummingbird"};
  int n1 = sizeof(a1)/sizeof(a1[0]);
  int n2 = sizeof(a2)/sizeof(a2[0]);

  show_len(a1,n1);
  show_len(a2,n2);
	
  return 0;
}
