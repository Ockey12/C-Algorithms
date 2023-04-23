#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int* a;
  int i, n = 4;

  a = calloc(n,sizeof(int));
  if(a == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }

  a[0] = 3;
  a[1] = 1;
  a[2] = 4;
  a[3] = 7;

  i=3;
  printf("%d,%d\n", i, i%n);
  i=4;
  printf("%d,%d\n\n", i, i%n);
  
  for(i = 0; i < n; i++){
    printf("%d=>%d\n", a[i%n], a[(i+1)%n]);
  }

  free(a);
  
  return 0;
}
