#include<stdio.h>
#include"ex3lib12.h"

int sum(TNODE* node)
{
  int n1 = 0, n2 = 0;

  if(node==NULL){
    return 0;
  }

  n1=sum(node->left);

  n2=sum(node->right);

  return node->data+n1+n2;
}

int main(void)
{
  int ans;
  TNODE node0 = {3};
  TNODE node1 = {1};
  TNODE node2 = {4};
  TNODE node3 = {7};
  TNODE node4 = {5};

  node0.left = &node1;
  node0.right = &node2;
  node1.left = &node3;
  node2.left = &node4;

  ans = sum(&node0);
  printf("%d\n", ans);

  ans = sum(&node1);
  printf("%d\n", ans);

  ans = sum(&node3);
  printf("%d\n", ans);

  return 0;
}
