#include<stdio.h>

typedef struct _dnode
{
  int data;
  struct _dnode *next;
  struct _dnode *prev;
} DNODE;

void CL_print(DNODE* head);

void np_swap(DNODE* dnode)
{
  DNODE* oldn;
  DNODE* oldp;

  oldn=dnode;
  oldp=dnode->prev;

  oldp->next=oldn->next;
  oldn->next->prev=oldp;
  oldn->next=oldp;
  oldn->prev=oldp->prev;
  oldp->prev->next=oldn;
  oldp->prev=oldn;

  return;

}

void CL_isort(DNODE* head)
{
  int n=0;
  int i,j,k;
  DNODE* tmp;

  tmp=head->next;
  while(tmp!=head){
    n++;
    tmp=tmp->next;
  }
  
  tmp=head->next;
  for(i=1; i<n; i++){
    for(j=0; j<i; j++){
      tmp=tmp->next;
    }
    for(k=i; k>0; k--){
      if(tmp->prev->data < tmp->data){
        break;
      }
      np_swap(tmp);
    }
    CL_print(head);
    tmp=head->next;
  }

  return;
}

int main(void)
{
  DNODE node[] = {{-123},{68},{44},{54},{95},{10},{27},{18}};
  DNODE *head  = &node[0];
  int i;
  int n = sizeof(node)/sizeof(node[0]);
  
  for(i = 0; i < n; i++){
    node[i].next = &node[(i+1)%n];
    node[(i+1)%n].prev = &node[i];
  }

  CL_print(head);  

  CL_isort(head);

  return 0;
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
