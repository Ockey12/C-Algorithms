#include<stdio.h>

int max3(int n1, int n2, int n3)
{
  /* ここにプログラムを書く */
  int max=n1;

  if(max<n2){
    max=n2;
  }

  if(max<n3){
    max=n3;
  }

  return max;
}

int main(void)
{
  int n[10],i;

  n[0] = max3(-3,-5,-19);
  n[1] = max3(-3,-19,-5);
  n[2] = max3(-5,-3,-19);
  n[3] = max3(-5,-19,-3);
  n[4] = max3(-19,-3,-5);
  n[5] = max3(-19,-5,-3);
  n[6] = max3(7,21,21);
  n[7] = max3(21,7,21);
  n[8] = max3(21,21,7);
  n[9] = max3(5,5,5);

  for(i = 0; i < 10; i++){
    printf("%d,",n[i]);
  }
  printf("\n");

  return 0;
}
