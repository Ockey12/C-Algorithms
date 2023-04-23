#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"ex3lib13.h"

void bst_delete(TNODE* pod, int val)
{
  TNODE* parent = pod;
  TNODE* node = pod->right;
  TNODE* sub;
  TNODE* pofsub;

  while(node!=NULL){
    if(node->data==val){
      break;
    }else if(node->data>val){
      parent=node;
      node=node->left;
    }else{
      parent=node;
      node=node->right;
    }
  }

  if(node==NULL){
    return;
  }

  if(node->right==NULL && node->left==NULL){
    sub=NULL;
  }else if(node->right!=NULL && node->left==NULL){
    sub=node->right;
  }else if(node->right==NULL && node->left!=NULL){
    sub=node->left;
  }else{
    if(node->left->right==NULL){
      sub=node->left;
      sub->right=node->right;
    }else{
      pofsub=node->left;
      sub=pofsub->right;
      while(sub->right!=NULL){
        pofsub=sub;
        sub=sub->right;
      }
      pofsub->right=sub->left;
      sub->left=node->left;
      sub->right=node->right;
    }
  }

  if(val < parent->data){
    parent->left=sub;
  }else{
    parent->right=sub;
  }

  free(node);

  return;
}

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
  bst_insert(&pod,1);
  bst_insert(&pod,0);
  bst_insert(&pod,2);
  bst_insert(&pod,4);
  bst_insert(&pod,6);
  bst_insert(&pod,5);

  print_tree(pod.right);
  printf("\n");

  bst_delete(&pod,3);

  print_tree(pod.right);
  printf("\n");

  bst_delete(&pod,2);

  print_tree(pod.right);
  printf("\n");

  bst_delete(&pod,0);

  print_tree(pod.right);
  printf("\n");

  bst_delete(&pod,6);

  print_tree(pod.right);
  printf("\n");

  bst_delete(&pod,4);

  print_tree(pod.right);
  printf("\n");

  free_tree(pod.right);

  return 0;
}
