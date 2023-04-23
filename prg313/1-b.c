#include<stdio.h>
#include<limits.h>
#include"ex3lib13.h"

int bst_searchl(TNODE* root, int val)
{
  TNODE* node = root;

  while(node!=NULL){
    if(node->data==val){
      return 1;
    }else if(node->data > val){
      node=node->left;
    }else{
      node=node->right;
    }
  }

  return 0;
}

int main(void)
{
  TNODE pod = {INT_MIN};
  TNODE node[] = {{0},{1},{2},{3},{4},{5},{6}};

  pod.right=&node[3];
  node[3].left=&node[1];
  node[3].right=&node[5];
  node[1].left=&node[0];
  node[1].right=&node[2];
  node[5].left=&node[4];
  node[5].right=&node[6];

  printf("%d\n",bst_searchl(pod.right,9));
  printf("%d\n",bst_searchl(pod.right,2));

  return 0;
}
