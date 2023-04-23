#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 4

typedef struct 
{
  int max;
  int sp;
  int* data;
} Stack;

void push(Stack* stack, int val)
{
  int old_max;
  int* new_data;
  int i;
  
  if(stack->sp == stack->max){
    old_max=stack->max;
    stack->max=old_max*2;
    printf("grow\n");

    new_data=calloc(stack->max,sizeof(int));
    if(stack == NULL){
      printf("ERROR\n");
      exit(EXIT_FAILURE);
    }

    for(i=0; i<old_max; i++){
      new_data[i]=stack->data[i];
    }
    free(stack->data);

    stack->data=new_data;

  }

  stack->data[stack->sp]=val;
  stack->sp++;

  return;
}

int pop(Stack* stack)
{
  if(stack->sp <= 0){
    printf("Stack is empty.\n");
    return -1;
  }
	
  stack->sp--;
  return stack->data[stack->sp];
}

void print_stack(Stack* stack)
{
  int i;
  printf("[ ");
  for(i = 0; i < stack->sp; i++){
    printf("%d ",stack->data[i]);
  }
  printf("]\n");
  return;
}

void init_stack(Stack* stack)
{
  stack->sp = 0;
  stack->data = calloc(stack->max, sizeof(int));
  if(stack->data == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  return;
}

int main(void)
{
  Stack stack = {INITSIZE};
  init_stack(&stack);

  print_stack(&stack);
  push(&stack, 3); print_stack(&stack);
  push(&stack, 1); print_stack(&stack);
  push(&stack, 4); print_stack(&stack);
  push(&stack, 7); print_stack(&stack);
  push(&stack, 5); print_stack(&stack);
  push(&stack, 9); print_stack(&stack);
  push(&stack, 2); print_stack(&stack);
  push(&stack, 6); print_stack(&stack);
  push(&stack, 8); print_stack(&stack);

  return 0;
}
