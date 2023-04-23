#include<stdio.h>
#include"ex3lib12.h"

typedef struct _lnode2
{
  int data;
  struct _lnode2* next;
} LNODE;

void LL_print2(LNODE* head);

void LL_insert(LNODE* head, LNODE* node) 
{
  LNODE* pos = head;

  while(pos->next!=NULL){
    if(pos->next->data > node->data){
      node->next=pos->next;
      pos->next=node;
      return;
    }
    pos=pos->next;
  }
  pos->next=node;

  return;
}

int main(void)
{
  LNODE node[] = {{-123},{18},{44},{59},{72}};
  LNODE node1 = {10};
  LNODE node2 = {86};
  LNODE node3 = {54};
  LNODE *head  = &node[0];
  int i;
  int n = sizeof(node)/sizeof(node[0]);
  
  for(i = 0; i < n - 1; i++){
    node[i].next = &node[i+1];
  }

  LL_print2(head);  

  LL_insert(head, &node1);  
  LL_print2(head);  

  LL_insert(head, &node2);  
  LL_print2(head);  

  LL_insert(head, &node3);  
  LL_print2(head);  

  return 0;
}

void LL_print2(LNODE* head)
{
  LNODE* pos = head->next;

  while(pos != NULL){
    printf("%d,",pos->data);
    pos = pos->next;
  }
  printf("\n");
  return;
}
