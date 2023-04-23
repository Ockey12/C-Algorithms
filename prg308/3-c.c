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

LNODE* LL_last_node(LNODE* head)
{
  LNODE *last=head;
  
  while(last->next!=NULL){
    last=last->next;
  }
  
  return last;
}

void LL_cat(LNODE* list1, LNODE* list2)
{
  LL_last_node(list1)->next=list2->next;

  return;
}

int main(void)
{
  LNODE node[] = {{0},{3},{7},{4},{1},{5},{9},{2},{6},{8}};
  int n  = sizeof(node)/sizeof(node[0]);
  int m = n/2;
  LNODE* list0 = &node[0];
  LNODE* list1 = &node[1];
  LNODE* list2 = &node[m];
  LNODE* tmp;
  int i;

  for(i = 1; i < m - 1; i++){
    node[i].next = &node[i+1];
  }
  for(i = m; i < n - 1; i++){
    node[i].next = &node[i+1];
  }

  tmp = LL_last_node(list0);
  printf("%d\n",tmp->data);
  tmp = LL_last_node(list1);
  printf("%d\n",tmp->data);

  LL_cat(list0,list1);
  LL_print(list0);

  LL_cat(list0,list2);
  LL_print(list0);

  return 0;
}
