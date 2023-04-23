#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ex3lib11.h"

void LL_print(LNODE* head)
{
  LNODE* pos = head->next;
  while(pos != NULL){
    printf("%s,",pos->data);
    pos = pos->next;
  }
  printf("\n");
  return;
}

LNODE* LL_search_val(LNODE* head, char* val)
{
  LNODE* pos = head->next;
  while(pos != NULL){
    if(strcmp(pos->data,val) == 0){
      return pos;
    }
    pos = pos->next;
  }
  return NULL;
}

LNODE* LL_insert_next(LNODE* pos, char* val)
{
  LNODE* new_node;
	
  new_node = calloc(1,sizeof(LNODE));
  if(new_node == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  new_node->data = val;
	
  new_node->next = pos->next;
  pos->next = new_node;
  return new_node;
}

char* LL_delete_next(LNODE* pos)
{
  LNODE* node;
  char* val;
	
  node = pos->next;
  pos->next=node->next;
  val = node->data;
  free(node);
  return val;
}

int LL_delete_val(LNODE* head, char* val)
{
  LNODE* pos = head;
  while(pos->next != NULL){
    if(strcmp(pos->next->data,val) == 0){
      LL_delete_next(pos);
      return 1;
    }
    pos = pos->next;
  }
  return 0;
}

void LL_init(LNODE* head)
{
  head->next = NULL;
  return;
}

STACK* LL_insert_next2(STACK* pos, int scp)
{
  STACK* node = calloc(1,sizeof(STACK));
  if(node == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
	
  node->data = scp;
  node->next = pos->next;
  pos->next = node;
  return node;
}

int LL_delete_next2(STACK* pos)
{
  STACK* node;
  int val;
	
  node = pos->next;
  pos->next=node->next;
  val = node->data;
  free(node);
	
  return val;
}

void push(STACK* stack, int val)
{
  LL_insert_next2(stack, val);
  return;
}

int pop(STACK* stack)
{
  if(stack->next == NULL){
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  }

  return LL_delete_next2(stack);
}

