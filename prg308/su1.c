#include<stdio.h>

int main(void)
{
  char str[] = "MIYAZAKI";

  printf("%c:", str[0]);
  printf("%p\n", &str[0]);

  printf("%c:", str[1]);
  printf("%p\n", &str[1]);
  
  printf("%c:", str[2]);
  printf("%p\n", &str[2]);

  return 0;
}
