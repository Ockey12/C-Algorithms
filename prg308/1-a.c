#include<stdio.h>

typedef struct _lnode
{
  int data;
  struct _lnode* next;
} LNODE;

int main(void)
{
  LNODE node0 = {3};
  LNODE node1 = {1};
  LNODE node2 = {4};
  LNODE node3 = {7};
  LNODE *pos,*head;

  node0.next = &node1;
  node1.next = &node2;
  node2.next = &node3;

  head = &node0;

  pos = head->next;

  while(pos != NULL){
    printf("%d,",pos->data);
    pos = pos->next;
  }
  printf("\n");

  return 0;
}
