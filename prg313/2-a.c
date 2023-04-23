#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"ex3lib13.h"

void bst_insert(TNODE* pot, int val)
{
  TNODE* parent = pot;
  TNODE* node = pot->right;
  TNODE* new_node;

  while(node!=NULL){
    if(node->data==val){
      return;
    }else if(node->data>val){
      parent=node;
      node=node->left;
    }else{
      parent=node;
      node=node->right;
    }
  }

  new_node = calloc(1,sizeof(TNODE));
  if(new_node == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }

  new_node->data=val;
  new_node->left=NULL;
  new_node->right=NULL;
  if(parent->data>val){
    parent->left=new_node;
  }else{
    parent->right=new_node;
  }

  return;
}

int main(void)
{
  TNODE pod = {INT_MIN};

  bst_insert(&pod,3);
  print_tree(pod.right);
  printf("\n");

  bst_insert(&pod,1);
  print_tree(pod.right);
  printf("\n");

  bst_insert(&pod,0);
  print_tree(pod.right);
  printf("\n");

  bst_insert(&pod,2);
  print_tree(pod.right);
  printf("\n");

  bst_insert(&pod,4);
  print_tree(pod.right);
  printf("\n");

  bst_insert(&pod,6);
  print_tree(pod.right);
  printf("\n");

  bst_insert(&pod,5);
  print_tree(pod.right);
  printf("\n");

  free_tree(pod.right);

  return 0;
}
