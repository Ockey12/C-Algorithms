#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"ex3lib13.h"

void bst_delete(TNODE* pod, int val)
{
  TNODE** adr = &(pod->right); // adrは、根のノードが入っているアドレスになる
  TNODE** adr2;
  TNODE* target;
  TNODE* sub;

  /* 【入力】
     adr番地に入っている値がNULLでない間、以下を繰り返す
     adr番地に入っているノード構造体のdataとvalが等しければ、
     削除対象がみつかったので、繰り返しを終了する。
     valの値が、adr番地に入っているノード構造体のdataより小さければ、
     adrの値を、そのノード構造体のメンバ変数leftのアドレスで置き換える。
     valの値が、adr番地に入っているノード構造体のdataより大きければ、
     adrの値を、そのノード構造体のメンバ変数rightのアドレスで置き換える。

     target（削除対象）をadr番地に入っているノード構造体にする。

     targetがNULLなら、（削除対象がなかったということなので）関数から抜けて終了

     targetの左の子がNULLなら、adr番地にtargetの右の子を入れる
     NULLでなく、targetの右の子がNULLなら、adr番地にtargetの左の子を入れる

     どちらの子もNULLでない場合は、以下を行う。
     targetの左の子のアドレスをadr2に入れておく
     adr2番地の右の子がNULLでない間、以下を繰り返す。
     　　adr2の値を、adr2番地に入っている構造体の右の子のアドレスで置き換える。
     上の繰り返しが終わった時、adr2番地に格納されている構造体を
     sub（置き換え用のノード）にする。
     adr2番地には、subの左の子を入れる。
     adr番地に構造体subを入れる。
     subの左にtargetの左の子、subの右にtargetの右の子を入れる。

     targetをfree()関数で解放する。

  */
  while(*adr!=NULL){
    if((*adr)->data==val){
      break;
    }else if((*adr)->data > val){
      adr=&((*adr)->left);
    }else{
      adr=&((*adr)->right);
    }
  }

  target=*adr;

  if(target==NULL){
    return;
  }else if(target->right!=NULL && target->left==NULL){
    *adr=target->right;
  }else if(target->right==NULL && target->left!=NULL){
    *adr=target->left;
  }else{
    adr2=&target;
    while((*adr2)->right!=NULL){
      adr2=&((*adr2)->right);
    }
    sub=*adr2;
    *adr2=sub->left;
    *adr=sub;
    sub->left=target->left;
    sub->right=target->right;
  }
  
  free(target);
  
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

  bst_delete(&pod,4);

  print_tree(pod.right);
  printf("\n");

  bst_delete(&pod,6);

  print_tree(pod.right);
  printf("\n");

  return 0;
}
