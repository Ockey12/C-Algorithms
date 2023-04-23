#include<stdio.h>
#include<string.h>

void swap(char*[], int, int);
void print_strings(char*[], int); 

void ssort(char* a [], int n)
{
  int i, j, max=0;

  for(i=n-1; i>0; i--){
    for(j=1; j<=i; j++){
      if(strlen(a[max])<strlen(a[j])){
        max=j;
      }else if(strlen(a[max])==strlen(a[j]) && strcmp(a[max],a[j])<0){
        max=j;
      }
    }
    swap(a,max,i);
    max=0;
  }

  return;
}

int main(void)
{
  char* a[] = {"puma", "leopard", "cheetah", "caracal", "serval", "lion", "cougar",
	       "jaguar", "tiger", "panther", "cat", "ocelot", "lynx", "margay"};
  int n = sizeof(a)/sizeof(a[0]);

  ssort(a, n);
  print_strings(a, n);

  return 0;
}

void swap(char* a[], int m, int n)
{
  char *c;

  c=a[m];
  a[m]=a[n];
  a[n]=c;

  return;
}

void print_strings(char* a[], int n)
{
  int i;

  for(i=0; i<n; i++){
    printf("%s\n",a[i]);
  }

  return;
}
