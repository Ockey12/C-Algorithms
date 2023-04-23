#include<stdio.h>
#include<string.h>

#define M 16

void print_array(char*[],int);

int main(void)
{
  char* bucket[M] = {NULL};
  char* a[] = {"gerbil", "ox", "tiger", "hare", "ouroboros", "serpent", "stallion", "ewe", "chimpanzee", "hummingbird"};
  int n = sizeof(a)/sizeof(a[0]);
  int i;

  for(i = 0; i < n; i++){
    bucket[strlen(a[i])]=a[i];
  }

  for(i = 0; i < M; i++){
    if(bucket[i]!=NULL){
      printf("%s,",bucket[i]);
    }
  }
  printf("\n");
  
  return 0;
}
