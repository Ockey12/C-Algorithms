#include<stdio.h>

typedef struct _lnode2
{
  int data;
  struct _lnode2* next;
} LNODE;

void LL_print2(LNODE*);
void LL_swap(LNODE*);

void LL_bubble_up(LNODE *head) 
{
  LNODE* pos;
  LNODE* last = NULL;

  if (head->next == NULL) {
    return;
  }

  pos = head;

  while(pos->next->next!=last){
    if(pos->next->data > pos->next->next->data){
      LL_swap(pos);
    }
    LL_print2(head);
    pos=pos->next;
  }
  
  return;
}

int main(void)
{
  LNODE node[] = {{-123},{59},{10},{44},{86},{54},{72},{18}};
  LNODE *head  = &node[0];
  int i;
  int n = sizeof(node)/sizeof(node[0]);
  
  for(i = 0; i < n - 1; i++){
    node[i].next = &node[i+1];
  }

  LL_print2(head);  

  LL_bubble_up(head);  

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

void LL_swap(LNODE *node)
{

  LNODE* node2 = node->next;
  LNODE* node3 = node2->next;
  LNODE* node4 = node3->next;

  node->next = node3;
  node3->next = node2;
  node2->next = node4;

  return;
}
