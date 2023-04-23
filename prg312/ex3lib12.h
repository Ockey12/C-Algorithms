#ifndef EX3LIB12_H
#define EX3LIB12_H

typedef struct _tnode
{
	int data;
	struct _tnode* left;
	struct _tnode* right;
} TNODE;

typedef struct _lnode
{
	TNODE* data;
	struct _lnode* next;
} STACK;

typedef struct _dnode
{
	TNODE* data;
	struct _dnode* next;
	struct _dnode* prev;
} QUEUE;

TNODE* compose_tree(int connection[][3],int n);
void free_tree(TNODE* root);
STACK* LL_insert_next(STACK* pos, TNODE* val);
TNODE* LL_delete_next(STACK* pos);
void push(STACK* stack, TNODE* val);
TNODE* pop(STACK* stack);
QUEUE* CL_insert_next(QUEUE* pos, TNODE* val);
TNODE* CL_delete(QUEUE* pos);
void enqueue(QUEUE* q, TNODE* val);
TNODE* dequeue(QUEUE* q);
void init_stack(STACK* stack);
void init_queue(QUEUE* q);

#endif

