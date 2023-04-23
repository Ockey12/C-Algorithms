#include<stdio.h>
#include"ex3lib12.h"

int main(void)
{
  int connection[][3] = {{3,1,2},{1,3,4},{4,5,6},
                         {7,-1,-1},{5,-1,-1},{9,-1,-1},{2,-1,-1}};
  int n = sizeof(connection)/sizeof(connection[0]);
  TNODE* root;
  STACK lnode;
  STACK* stack = &lnode;
  TNODE* node;

  init_stack(stack);

  root = compose_tree(connection, n);
  if(root == NULL){
    return 0;
  }

  push(stack,root);

  while(n-- > 0){
    node=pop(stack);
    printf("%d,", node->data);

    push(stack,node->right);
    push(stack,node->left);
  }
  printf("\n");

  free_tree(root);

  return 0;
}
