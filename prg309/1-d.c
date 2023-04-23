#include<stdio.h>
#include<stdlib.h>

#define N 8

typedef struct _dnode
{
  int data;
  struct _dnode *next;
  struct _dnode *prev;
} DNODE;

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
  DNODE *head, *node;
  int a[] = {-123,3,1,4,7};
  int n = sizeof(a)/sizeof(a[0]);
  int i;
  
  node = calloc(n,sizeof(DNODE));
  if(node == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < n; i++){
    node[i].data=a[i];
  }

  for(i = 0; i < n; i++){
    node[i%n].next=&node[(i+1)%n];
    node[(i+1)%n].prev=&node[i%n];
  }
  
  head = &node[0];
  
  CL_print(head);
  CL_print_rev(head);

  free(node);
  
  return 0;
}
