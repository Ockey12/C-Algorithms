#include<stdio.h>

typedef struct _lnode2
{
  int data;
  struct _lnode2 *next;
} LNODE2;

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

int main(void)
{
  LNODE2 node[] = {{-123},{59},{10},{44},{86},{54},{72},{18}};
  LNODE2 *head  = &node[0];
  LNODE2 *tmp;
  
  int i;
  int n = sizeof(node)/sizeof(node[0]);
  
  for(i = 0; i < n - 1; i++){
    node[i].next = &node[i+1];
  }

  LL_print2(head);  

  tmp = head;
  LL_swap(tmp);
  LL_print2(head);  

  tmp = &node[1];
  if(tmp->next->data >= tmp->next->next->data){
    LL_swap(tmp);
  }
  LL_print2(head);  

  tmp = &node[3];
  if(tmp->next->data >= tmp->next->next->data){
    LL_swap(tmp);
  }
  LL_print2(head);  

  return 0;
}
