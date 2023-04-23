#include<stdio.h>
#include<string.h>

void print_strings(char* [], int);

void isort(char* a[], int n)
{
  int i, j;
  char* tmp;

  for(i=1; i<n; i++){
    tmp=a[i];
    for(j=i; j>0; j--){
      if(strlen(a[j-1])<=strlen(tmp)){
        break;
      }
      a[j]=a[j-1];
    }
    a[j]=tmp;
  }

  return;
}

int main(void)
{
  char* a[] = {"puma", "leopard", "cheetah", "caracal", "serval", "lion",
	       "cougar", "jaguar", "tiger", "panther", "cat", "ocelot", "lynx", "margay"};
  int n = sizeof(a)/sizeof(a[0]);

  isort(a, n);

  print_strings(a, n);

  return 0;
}

void print_strings(char* a[], int n)
{
  int i;

  for(i = 0; i < n; i++){
    printf("%s\n",a[i]);
  }
  
  return;
}
