#ifndef EX3LIB11_H
#define EX3LIB11_H

typedef struct _lnode
{
  char* data;
  struct _lnode* next;
} LNODE;

typedef struct _lnode2
{
  int data;
  struct _lnode2* next;
} STACK;


void LL_print(LNODE* head);
LNODE* LL_search_val(LNODE* head, char* val);
LNODE* LL_insert_next(LNODE* pos, char* val);
char* LL_delete_next(LNODE* pos);
int LL_delete_val(LNODE* head, char* val);
void LL_init(LNODE* head);
STACK* LL_insert_next2(STACK* pos, int scp);
int LL_delete_next2(STACK* pos);
void push(STACK* stack, int val);
int pop(STACK* stack);

#endif
