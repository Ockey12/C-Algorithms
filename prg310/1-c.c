#include<stdio.h>
#include<string.h>

#define M 16

void print_array(char*[],int);

int main(void)
{
  char* bucket[M] = {NULL};
  char* a[] = {"gerbil", "ox", "tiger", "hare", "ouroboros", "serpent", "stallion", "ewe", "chimpanzee", "bummingbird"};
  int n = sizeof(a)/sizeof(a[0]);
  int i, j;

  print_array(a, n); 

  for(i = 0; i < n; i++){
    bucket[strlen(a[i])]=a[i];
  }

  j = 0;
  for(i = 0; i < M; i++){ 
    if(bucket[i]!=NULL){
      a[j]=bucket[i];
      j++;
    }
  }
  
  print_array(a, n); 

  return 0;
}

void print_array(char* a[], int n)
{
  int i;
  for(i = 0; i < n; i++){
    printf("%s,",a[i]);
  }
  printf("\n");
  return;
}
