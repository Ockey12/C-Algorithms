#include<stdio.h>

typedef struct _lnode2
{
  int data;
  struct _lnode2 *next;
} LNODE2;

void LL_swap(LNODE2 *node);
void LL_print2(LNODE2* head);

void LL_bsort(LNODE2 *head)
{
  int i, j;
  int n=0;
  int n2;
  LNODE2 *pos;

  pos=head->next;

  while(pos!=NULL){
    n++;
    pos=pos->next;
  }

  pos=head;
  n2=n-1;

  for(i=1; i<n; i++){
    for(j=0; j<n2; j++){
      if(pos->next->data > pos->next->next->data){
        LL_swap(pos);
      }
      pos=pos->next;
    }
    LL_print2(head);
    pos=head;
    n2--;
  }

  return;
}

int main(void)
{
  LNODE2 node[] = {{-123},{59},{10},{44},{86},{54},{72},{18}};
  LNODE2 *head  = &node[0];
  int i;
  int n = sizeof(node)/sizeof(node[0]);
  
  for(i = 0; i < n - 1; i++){
    node[i].next = &node[i+1];
  }

  LL_print2(head);

  LL_bsort(head);

  return 0;
}

void LL_swap(LNODE2 *node)
{
  LNODE2 *next;
  LNODE2 *next_next;

  next=node->next;
  next_next=node->next->next;

  next->next=next_next->next;
  next_next->next=next;
  node->next=next_next;

  return;
}

void LL_print2(LNODE2* head)
{
  LNODE2* pos = head->next;

  while(pos != NULL){
    printf("%d,",pos->data);
    pos = pos->next;
  }
  printf("\n");
  return;
}
