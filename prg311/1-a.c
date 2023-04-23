#include<stdio.h>
#include<string.h>

int main(void)
{
  char str1[] = "cat";
  char str2[] = "cat";
  int n;

  n = strlen(str1);
  printf("%d\n",n);

  if(strcmp(str1,str2)==0){
    printf("EQUAL\n");
  } else {
    printf("NOT EQUAL\n");
  }

  return 0;
}
