#include<stdio.h>

typedef struct _lnode2
{
  int data;
  struct _lnode2* next;
} LNODE;

void LL_print2(LNODE* head);

void LL_ssort(LNODE *head)
{
  LNODE* pnm;
  LNODE* cur;
  LNODE* last = NULL;

  if (head->next == NULL) {
    return;
  }

  pnm=head;
  cur=head->next;
  while(cur->next!=last){
    while(cur->next!=last){
      if(pnm->next->data < cur->next->data){
	pnm=cur;
      }
      cur=cur->next;
    }
    if(pnm->next==cur && cur->next==last){
      last=cur;
    }else{
      cur->next=pnm->next;
      pnm->next=pnm->next->next;
      cur->next->next=last;
      last=cur->next;
    }
 
    pnm=head;
    cur=head->next;
    LL_print2(head);  
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

  LL_ssort(head);  

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
