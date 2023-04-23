#include<stdio.h>

int main(void)
{
  char str[] = "MIYAZAKI";
  char *p = str;
  
  printf("%s\n", &str[0]);
  printf("%s\n", &str[2]);
  printf("%s\n", str + 5);
  
  printf("%c\n", p[4]);
  
  return 0;
}
