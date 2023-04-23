#include<stdio.h>
#include"ex3lib13.h"

int main(void){
  int n;
  int* np;
  int** pp;
  TNODE n0={3};
  TNODE n1={4};
  TNODE n2={5};
  TNODE** adr;

  n=5;
  np=&n;
  pp=&np;

  printf("%d\n",n);
  printf("%d\n",*np);
  printf("%d\n",**pp);

  adr=&(n0.left);
  *adr=&n1;
  adr=&(n0.right);
  *adr=&n2;

  printf("%d,%d\n",n0.left->data,n0.right->data);

  return 0;
}
