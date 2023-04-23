#include<stdio.h>

int test(void)
{
  int n=0;

  n++;

  return n;
}

int test2(void)
{
  static int n=0;

  n++;

  return n;
}

int test3(int n)
{
  int i=0;
  static int a[8]={0,0,0,0,0,0,0,0};
  static int m=0;

  a[m]=n;
  m++;

  for(; i<8; i++){
    printf("%d,",a[i]);
  }
  printf("\n");

  return n;
}

int main(void)
{
  int i;

  for(i=0; i<10; i++){
    printf("%d,",test());
  }
  printf("\n");

  for(i=0; i<10; i++){
    printf("%d,",test2());
  }
  printf("\n");

  test3(31);
  test3(41);
  test3(59);
  test3(26);

  return 0;
}
