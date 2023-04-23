#include<stdio.h>

int main(void)
{
  char str[] = "MIYAZAKI";

  printf("%p\n", &str[0]);
  printf("%p\n", str);

  printf("%c\n", *(str + 3));
  printf("%c\n", str[3]);

  return 0;
}
