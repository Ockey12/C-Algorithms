#include<stdio.h>

int main(void)
{
  int head = 0, tail = 8;
  while(head <= tail){
    printf("%d:%d\n",head,tail);
    head++;
    tail--;
  }

  return 0;
}
