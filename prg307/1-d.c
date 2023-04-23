#include<stdio.h>
#define QSIZE 8

int main(void)
{
  int front = 5;
  int size = 6;
  int i;

  for(i=0; i<size; i++){
    printf("%d\n", (front+i)%QSIZE);
  }

  return 0;
}
