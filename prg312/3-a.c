#include<stdio.h>
#include"ex3lib12.h"

int main(void)
{
  int connection[][3] = {{3,1,2},{1,3,4},{4,5,6},
                         {7,-1,-1},{5,-1,-1},{9,-1,-1},{2,-1,-1}};
  int n = sizeof(connection)/sizeof(connection[0]);
  TNODE* root;
  QUEUE dnode;
  QUEUE* q = &dnode;
  TNODE* node;

  init_queue(q);
  
  root = compose_tree(connection, n);
  if(root == NULL){
    return 0;
  }

  enqueue(q,root);

  while(n-- > 0){
    node=dequeue(q);
    printf("%d,",node->data);

    enqueue(q,node->left);
    enqueue(q,node->right);
  }
  printf("\n");

  free_tree(root);

  return 0;
}
