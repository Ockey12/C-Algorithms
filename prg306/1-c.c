#include<stdio.h>

struct Time
{
  int hour;
  int min;
  int sec;
};

int main(void)
{
  struct Time t1={14,29,43};

  printf("%d:%d:%d\n",t1.hour,t1.min,t1.sec);

  return 0;
}
