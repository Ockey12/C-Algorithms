#include<stdio.h>
#include<string.h>

void print_strings(char* a[], int n);
void swap(char* a[], int m, int n);

void busort(char* a[], int n)
{
  
  int i, j;
  int n2=n-1;

  for(i=1; i<n; i++){
    for(j=0; j<n2; j++){
      if(strcmp(a[j],a[j+1])>0){
        swap(a,j,j+1);
      }
    }
    n2--;
  }
}

int main(void)
{
  char* a[] = {"gerbil", "ox", "tiger", "hare", "ouroboros", "serpent",
	       "stallion", "ewe", "chimpanzee", "hummingbird"};
  int n = sizeof(a)/sizeof(a[0]);

  busort(a,n);
  print_strings(a,n);
	
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
    printf("%s\n", a[i]);
  }

  return;
}

