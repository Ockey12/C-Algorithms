#include<stdio.h>
#include<stdlib.h>

typedef struct _lnode
{
  int data;
  struct _lnode* next;
} LNODE;

LNODE* LL_search_prev_of(LNODE* head,int val)
{
  LNODE *pos;
  pos = head;
  
  while(pos->next != NULL){
    if(pos->next->data == val){
      return pos;
    }
    pos = pos->next;
  }

  return NULL;
}

int LL_delete_next(LNODE* lnode)
{
  LNODE* old_next;
  LNODE* new_next;
  int val;

  old_next=lnode->next;
  new_next=old_next->next;
  val=old_next->data;
  lnode->next=new_next;
  free(old_next);

  return val;
}

LNODE* LL_insert_next(LNODE* lnode, int val)
{
  LNODE* old_next;
  LNODE* new_next;

  old_next=lnode->next;

  new_next=calloc(1,sizeof(LNODE));
  if(new_next == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  new_next->data=val;

  lnode->next=new_next;
  new_next->next=old_next;

  return new_next;
}

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

void LL_free(LNODE* head)
{
  LNODE *pos, *next_pos;

  pos=head->next;
  
  while(pos != NULL){
    next_pos=pos->next;
    free(pos);
    pos=next_pos;
  }

  return;
}

int main(void)
{
  LNODE* tmp;
  LNODE node;
  LNODE* head = &node;
  head->next=NULL;

  LL_insert_next(head,3);
  LL_insert_next(head,1);
  LL_insert_next(head,4);
  LL_insert_next(head,7);

  LL_print(head);

  tmp = LL_search_prev_of(head,1);
  LL_delete_next(tmp);
  LL_print(head);

  tmp = LL_search_prev_of(head,3);
  LL_delete_next(tmp);
  LL_print(head);

  tmp = LL_search_prev_of(head,7);
  LL_delete_next(tmp);
  LL_print(head);

  LL_free(head);

  return 0;
}
