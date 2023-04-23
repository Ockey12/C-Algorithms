#include<stdio.h>
#include<stdlib.h>

#define N 8

typedef struct _dnode
{
  int data;
  struct _dnode *next;
  struct _dnode *prev;
} DNODE;

DNODE* CL_search(DNODE* head, int val)
{
  DNODE *pos;
  pos = head->next;
  
  while(pos != head){
    if(pos->data == val){
      return pos;
    }
    pos = pos->next;
  }

  return NULL;
}

DNODE* CL_insert_next(DNODE* dnode, int val)
{
  DNODE *old_next, *new_next;

  old_next=dnode->next;

  new_next=calloc(1,sizeof(DNODE));
  if(new_next == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  new_next->data=val;

  dnode->next=new_next;
  new_next->prev=dnode;
  new_next->next=old_next;
  old_next->prev=new_next;

  return new_next;
}

void CL_init(DNODE* head)
{
  head->next = head->prev = head;
  return;
}

void CL_print(DNODE* head)
{
  DNODE* pos = head->next;

  while(pos != head){
    printf("%d,",pos->data);
    pos = pos->next;
  }
  printf("\n");
  return;
}

void CL_print_rev(DNODE* head)
{
  DNODE *pos;
  pos=head->prev;

  while(pos!=head){
    printf("%d,", pos->data);
    pos=pos->prev;
  }
  printf("\n");

  return;
}

int main(void)
{
  DNODE node;
  DNODE *head, *nodep;

  head = &node;
  head->data = -123;
  CL_init(head);
  
  CL_insert_next(head,3);
  CL_insert_next(head,1);
  CL_insert_next(head,4);
  CL_insert_next(head,7);
  
  CL_print(head);
  CL_print_rev(head);


  nodep = CL_search(head,15);
  if(nodep == NULL){
    printf("Not found.\n");
  }
  
  nodep = CL_search(head,4);
  CL_insert_next(nodep,8);
  
  CL_print(head);
  CL_print_rev(head);
  
  nodep = CL_search(head,7);
  CL_insert_next(nodep,6);
  
  CL_print(head);
  CL_print_rev(head);

  return 0;
}
