#include<stdio.h>
#include<limits.h>
#include"ex3lib13.h"

int bst_searchr(TNODE* node, int val)
{
  if(node==NULL){
    return 0;
  }

  if(node->data==val){
    return 1;
  }else if(node->data > val){
    return bst_searchr(node->left,val);
  }else{
    return bst_searchr(node->right,val);
  }

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

  printf("%d\n",bst_searchr(pod.right,4));
  printf("%d\n",bst_searchr(pod.right,14));

  return 0;
}
