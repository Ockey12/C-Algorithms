#include<stdio.h>

#define N 10

int main(void)
{
  char* str[] = {"abcd", "efgh", "ijkl", "mnop", "qrst", "uvwx"};
  int n = 385;
  int k = 1;

  printf("%s\n", str[3]);
  printf("%c\n", str[4][0]);

  printf("%d", (n / k) % N);

  k = k * N;
  printf("%d", (n / k) % N);

  k = k * N;
  printf("%d", (n / k) % N);
  
  printf("\n");

  for (k = 1; k < 1000; k *= N) {
    printf("%d", (n/k)%N);
  }
  printf("\n");
  
  return 0;
}
