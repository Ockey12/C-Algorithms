#include<stdio.h>
#include<stdlib.h>

typedef struct _dnode
{
  int data;
  struct _dnode *next;
  struct _dnode *prev;
} DNODE;

DNODE* CL_insert_next(DNODE*, int);
int CL_delete(DNODE*);
void CL_init(DNODE*);
void CL_free(DNODE*);

void CL_print2(DNODE* head)
{
  DNODE* pos = head->next;

  while(pos != head){
    printf("%d ",pos->data);
    pos = pos->next;
  }
  return;
}

void enqueue(DNODE* q, int val)
{
  CL_insert_next(q->prev, val);

  return;
}

int dequeue(DNODE* q)
{
  int val;
  if(q->next == q){
    printf("Queue is empty.\n");
    return -1;
  }

  val=CL_delete(q->next);

  return val;
}

void print_queue(DNODE* q)
{
  printf("[ ");
  CL_print2(q);
  printf("]\n");
  return ;
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

int CL_delete(DNODE* dnode)
{
  DNODE* prev_node, *next_node;
  int val;

  val=dnode->data;
  prev_node=dnode->prev;
  next_node=dnode->next;

  prev_node->next=next_node;
  next_node->prev=prev_node;

  free(dnode);

  return val;
}

void CL_init(DNODE* head)
{
  head->next = head->prev = head;
  return;
}

void CL_free(DNODE* head)
{
  DNODE *pos, *prev_pos;

  pos=head->prev;
  while(pos != head){
    prev_pos=pos->prev;
    prev_pos->next=NULL;
    free(pos);
    pos=prev_pos;
  }
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

int main(void)
{
  DNODE node;
  DNODE *q;
  int n1,n2,n3;
  
  q = &node;  
  CL_init(q);

  print_queue(q);
  n1 = dequeue(q); print_queue(q);
  enqueue(q,13);    print_queue(q);
  n2 = dequeue(q); print_queue(q);
  enqueue(q,3);    print_queue(q);
  enqueue(q,1);    print_queue(q);
  enqueue(q,4);    print_queue(q);
  enqueue(q,7);    print_queue(q);
  n3 = dequeue(q); print_queue(q);
  enqueue(q,5);    print_queue(q);
  printf("%d,%d,%d\n",n1,n2,n3);
  
  CL_free(q);

  return 0;
}
