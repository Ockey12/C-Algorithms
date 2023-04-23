#include<stdio.h>

int main(void)
{
  char str[] = "MIYAZAKI";
  char* p0 = &str[0];
  char* p1 = &str[1];
  char* p2 = &str[2];

  printf("p1:   %p\n", p1);
  printf("p0+1: %p\n", p0+1);
  printf("*(p1):   %c\n", *(p1));
  printf("*(p0+1): %c\n", *(p0+1));

  printf("p2:   %p\n", p2);
  printf("p0+2: %p\n", p0+2);
  printf("*(p2):   %c\n", *(p2));
  printf("*(p0+2): %c\n", *(p0+2));

  return 0;
}
