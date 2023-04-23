#include<stdio.h>

typedef struct _lnode
{
  int data;
  struct _lnode* next;
} LNODE;

void LL_print(LNODE* head)
{
  LNODE *pos;
  pos = head->next;
  
  while(pos != NULL){
    printf("%d,",pos->data);
    pos = pos->next;
  }
  printf("\n");

  return;
}

int main(void)
{
  LNODE node[] = {{0},{1},{3},{4},{7}};

  node[0].next = &node[2];
  node[2].next = &node[4];
  node[4].next = &node[3];
  node[3].next = &node[1];

  LL_print(&node[0]);

  return 0;
}
