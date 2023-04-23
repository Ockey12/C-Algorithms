#include<stdio.h>
#include"ex3lib12.h"

void print_tree(TNODE* node);

int main(void)
{
  int connection[][3] = {{3,1,2},{1,3,4},{4,5,-1},{7,-1,-1},{5,6,7},{9,-1,8},{2,-1,-1},{6,-1,-1},{8,-1,-1}};
  int n = sizeof(connection)/sizeof(connection[0]);
  TNODE* root;

  root = compose_tree(connection, n);

  print_tree(root);
  printf("\n");

  free_tree(root);

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
