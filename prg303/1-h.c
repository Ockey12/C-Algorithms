#include<stdio.h>

int main(void)
{
  char dummy[] = "ABCDEFGHIJKLMNO";
  char str[] = "abcdefghijklmno";
  char dummy2[] = "ABCDEFGHIJKLMNO";
  int n = sizeof(str)/sizeof(str[0]);
  int i;
  char tmp;

  int m = n-1;

  printf("%c\n",str[ m-1 ]);

  tmp = str[0];

  for(i=0; i<m-1; i++){
    str[i] = str[i+1];
  }
  str[i] = tmp;

  printf("%s\n",dummy);
  printf("%s\n",str);
  printf("%s\n",dummy2);

  return 0;
}
