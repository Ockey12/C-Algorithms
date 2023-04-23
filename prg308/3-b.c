#include<stdio.h>

typedef struct _lnode
{
  int data;
  struct _lnode* next;
} LNODE;

void LL_print2(LNODE* head)
{
  LNODE *pos;
  
  if(head->next==NULL){
    return;
  }
  
  pos = head->next;
  
  LL_print2(pos);
  printf("%d ",pos->data);

  return;
}

LNODE* LL_insert_next(LNODE* pos, LNODE* node)
{
  node->next=pos->next;
  pos->next=node;

  return node;
}

int LL_delete_next(LNODE* pos)
{
  int val;

  val=pos->next->data;
  pos->next=pos->next->next;

  return val;
}

void push(LNODE* stack, LNODE* node)
{
  LL_insert_next(stack,node);

  return;
}

int pop(LNODE* stack)
{
  if(stack->next == NULL){
    printf("Stack is empty.\n");
    return -1;
  }

  return LL_delete_next(stack);
}

void print_stack(LNODE* stack)
{
  printf("[ ");

  LL_print2(stack);

  printf("]\n");

  return;
}

int main(void)
{
  LNODE lnode[] = {{0},{3},{1},{4},{7}};
  int n1,n2;
  LNODE* stack = &lnode[0];

  print_stack(stack);
  n1 = pop(stack);        print_stack(stack);
  push(stack,&lnode[1]);  print_stack(stack);
  push(stack,&lnode[2]);  print_stack(stack);
  push(stack,&lnode[3]);  print_stack(stack);
  push(stack,&lnode[4]);  print_stack(stack);
  n2 = pop(stack);        print_stack(stack);
  printf("%d,%d\n",n1,n2);

  return 0;
}
