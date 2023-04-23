#include<stdio.h>

typedef struct _lnode
{
  int data;
  struct _lnode* next;
} LNODE;

LNODE* LL_search_val(LNODE* head, int val)
{
  LNODE *pos;
  pos = head->next;
  
  while(pos != NULL){
    if(pos->data == val){
      return pos;
    }
    pos = pos->next;
  }

  return NULL;
}

int main(void)
{
  LNODE node[] = {{0},{3},{1},{4},{7}};
  int n = sizeof(node)/sizeof(node[0]);
  int i;
  LNODE* head = &node[0];
  LNODE* tmp;

  for(i = 0; i < n - 1; i++){
    node[i].next = &node[i+1];
  }

  tmp = LL_search_val(head,3);
  if(tmp == NULL){
    printf("Not found.\n");
  } else {
    printf("%d found.\n",tmp->data);
  }

  tmp = LL_search_val(head,4);
  if(tmp == NULL){
    printf("Not found.\n");
  } else {
    printf("%d found.\n",tmp->data);
  }

  tmp = LL_search_val(head,5);
  if(tmp == NULL){
    printf("Not found.\n");
  } else {
    printf("%d found.\n",tmp->data);
  }

  return 0;
}
