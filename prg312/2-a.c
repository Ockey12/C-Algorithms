#include<stdio.h>
#include"ex3lib12.h"

int sum(TNODE* root)
{
  int ans;

  ans=root->data;

  if(root->left!=NULL){
    ans+=sum(root->left);
  }

  if(root->right!=NULL){
    ans+=sum(root->right);
  }

  return ans;
}

int size(TNODE* root)
{
  int ans=1;

  if(root->left!=NULL){
    ans+=size(root->left);
  }
  
  if(root->right!=NULL){
    ans+=size(root->right);
  }

  return ans;
}

int height(TNODE* root)
{
  int ans=-1;
  int ans1;

  if(root->left!=NULL){
    ans1=height(root->left);
    if(ans<ans1){
      ans=ans1;
    }
  }

  if(root->right!=NULL){
    ans1=height(root->right);
    if(ans<ans1){
      ans=ans1;
    }
  }

  return ans+1;    
}

int max(TNODE* root)
{
  int ans=root->data;
  int ans1;

  if(root->left!=NULL){
    ans1=max(root->left);
    if(ans<ans1){
      ans=ans1;
    }
  }

  if(root->right!=NULL){
    ans1=max(root->right);
    if(ans<ans1){
      ans=ans1;
    }
  }

  return ans;
}

int main(void)
{
  int connection[][3] = {
    {10, 1, 2}, {4, 3, 4}, {12, -1, 5}, {2, 6, -1}, {9, 7, 8}, {11, 9, 10},
    {7, -1, 11}, {1, -1, -1}, {6, 12, 13}, {15, -1, 14}, {0, -1, 15},
    {5, -1, -1}, {8, -1, -1}, {3, -1, -1}, {13, -1, -1}, {14, -1, -1}
  };
  int n = sizeof(connection) / sizeof(connection[0]);
  TNODE* root;
  int connection2[][3] = {
    {10, 1, 6}, {4, -1, 2}, {3, 3, -1}, {2, -1, 4},
    {1, 5, -1}, {0, -1, -1},{5, -1, -1}
  };
  int n2 = sizeof(connection2) / sizeof(connection2[0]);
  TNODE* root2;

  root = compose_tree(connection, n);
  root2 = compose_tree(connection2, n2);

  printf("sum = %d\n", sum(root));
  printf("size = %d\n", size(root));
  printf("max = %d\n", max(root));
  printf("height = %d\n\n", height(root));
  printf("max = %d\n", max(root2));
  printf("height = %d\n", height(root2));

  free_tree(root);
  free_tree(root2);

  return 0;
}
