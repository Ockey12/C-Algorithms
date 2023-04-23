#include<stdio.h>
#include"ex3lib12.h"

void print_tree(TNODE* node);

int main(void)
{
  TNODE node0 = {3};
  TNODE node1 = {1};
  TNODE node2 = {4};
  TNODE node3 = {7};
  TNODE node4 = {5};
  TNODE node5 = {9};

  node0.left = &node1;
  node0.right = &node2;
  node1.right = &node3;
  node3.left = &node4;
  node3.right = &node5;

  print_tree(&node0);
  printf("\n");
  return 0;
}

void print_tree(TNODE* node)
{
  if(node == NULL){
    printf("*");
    return;
  }

  printf("( ");
  print_tree(node->left);
  printf(" %d ",node->data);
  print_tree(node->right);
  printf(" )");

  return;
}
