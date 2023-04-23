#include<stdio.h>
#include"ex3lib12.h"

int sum(TNODE* node)
{
  int ans;

  ans=node->data;

  if(node->left!=NULL){
    ans+=sum(node->left);
  }

  if(node->right!=NULL){
    ans+=sum(node->right);
  }

  return ans;
}

int main(void)
{
  int ans;
  TNODE node0 = {1};
  TNODE node1 = {9};
  TNODE node2 = {6};
  TNODE node3 = {4};
  TNODE node4 = {8};

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
