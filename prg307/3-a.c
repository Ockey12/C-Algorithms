#include<stdio.h>
#include<string.h>

void print_strings(char* a[], int n);
void swap(char* a[], int m, int n);

void qsort(char* a[], int left, int right)
{
  int i,j;
  char *pivot=a[(right+left)/2];

  if(right-left < 1){
    return;
  }

  i=left;
  j=right;

  while (1){
    while (strcmp(a[i],pivot)<0){
      i++;
    }

    while (strcmp(a[j],pivot)>0){
      j--;
    }

    if(i>=j){
      break;
    }

    swap(a, i, j);

    i++;
    j--;

  }

  qsort(a, left, i-1);
  qsort(a, j+1, right);

  return;
}

int main(void)
{
  char* a[] = {"puma", "leopard", "cheetah", "caracal", "serval", "lion", "cougar","jaguar", "tiger", "panther", "cat", "ocelot", "lynx", "margay"};
  int n = sizeof(a)/sizeof(a[0]);

  qsort(a, 0, n - 1);
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
    printf("%s\n", a[i]);
  }

  return;
}
