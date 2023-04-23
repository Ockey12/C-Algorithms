#include<stdio.h>
#include<stdlib.h>

/* 1-d, 1-e, 2-a, 2-b用 */
/*
#define FMT "%d,"
#define FMT2 "%d "
#define EMPTY -1

typedef int dtype;
*/

/* 3-a, 3-b用 */
#define FMT "%s,"
#define FMT2 "%s "
#define EMPTY NULL

typedef char* dtype;

typedef struct _lnode
{
  dtype data;
  struct _lnode* next;
} LNODE;

void LL_print_rev(LNODE* lnode)
{
  if (lnode == NULL) {
    return;
  }

  LL_print_rev(lnode->next);
  printf(FMT2, lnode->data);

  return;
}

void LL_insert_next(LNODE* node, dtype val)
{
  LNODE* new_next = calloc(1,sizeof(LNODE));
  if (new_next == NULL) {
    printf("Memory Allocation Error.\n");
    exit(EXIT_FAILURE);
  }

  new_next->data = val;
  new_next->next = node->next;
  node->next = new_next;

  return;
}

dtype LL_delete_next(LNODE* node)
{
  LNODE* old_next = node->next;
  dtype val = old_next->data;
  node->next = old_next->next;
  free(old_next);
  return val;
}

void push(LNODE* stack, dtype val)
{
  LL_insert_next(stack, val);
  return;
}

dtype pop(LNODE* stack)
{
  if (stack->next == NULL){
    printf("Stack is empty.\n");
    return EMPTY;
  }

  return LL_delete_next(stack);
}

int empty(LNODE* stack)
{
  return stack->next == NULL;
}

void print_stack(LNODE* stack)
{
  printf("[ ");
  LL_print_rev(stack->next);
  printf("]\n");
}

void print_array(dtype a[], int n)
{
  int i;
  for (i = 0; i < n; i++){
    printf(FMT, a[i]);
  }
  printf("\n");
  return;
}
