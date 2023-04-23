#include<stdio.h>
#include"ex3lib12.h"

void print_preorder(TNODE* node)
{
  if(node == NULL){
    return;
  }
  
  printf("%d,",node->data);
  print_preorder(node->left);
  print_preorder(node->right);

  return;
}

void print_inorder(TNODE* node)
{
  if(node == NULL){
    return;
  }
  
  print_inorder(node->left);
  printf("%d,",node->data);
  print_inorder(node->right);

  return;
}

void print_postorder(TNODE* node)
{
  if(node == NULL){
    return;
  }
  
  print_postorder(node->left);
  print_postorder(node->right);
  printf("%d,",node->data);

  return;
}

int main(void)
{
  int connection[][3] = {{1,1,2},{9,3,-1},{6,-1,4},{4,-1,-1},{8,-1,-1}};
  int n = sizeof(connection)/sizeof(connection[0]);
  TNODE* root;

  root = compose_tree(connection, n);

  print_preorder(root);
  printf("\n");

  print_inorder(root);
  printf("\n");

  print_postorder(root);
  printf("\n");

  free_tree(root);

  return 0;
}
