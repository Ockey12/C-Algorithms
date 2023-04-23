#include<stdio.h>
#include<string.h>

int main(void)
{
  char dummy[] = "aaaaaaaaaaaaaaa";
  char str[] = "ABCDEFGHIJKLMNO";
  char dummy2[] = "zzzzzzzzzzzzzzz";
  int n = strlen(str);
  int i;
  
  printf("%c\n",str[n-1]);
  printf("%s\n",str);

  for(i=n-1; i>0; i--){
    str[i]=str[i-1];
  }
  
  printf("%s\n",str);
  printf("%s\n",dummy);
  printf("%s\n",dummy2);

  return 0;
}
