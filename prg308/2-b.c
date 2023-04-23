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

LNODE* LL_search_val(LNODE* head, int val)
{
  LNODE *pos;
  pos = head->next;
  
  while(pos != NULL){
    if(pos->data == val){
      return pos;
    }
    pos = pos->next;
  }

  return NULL;
}

LNODE* LL_insert_next(LNODE* pos, LNODE* lnode)
{
  lnode->next=pos->next;
  pos->next=lnode;

  return lnode;
}

int main(void)
{
  LNODE lnode[] = {{0},{3},{1},{4},{7}};
  int n = sizeof(lnode)/sizeof(lnode[0]);
  int i;
  LNODE* head = &lnode[0];
  LNODE* pos;
  LNODE node = {10};

  for(i = 0; i < n - 1; i++){
    lnode[i].next = &lnode[i+1];
  }

  pos = LL_search_val(head,4);
  if(pos != NULL){
    LL_insert_next(pos,&node);
  }

  LL_print(head);

  return 0;
}
