#include<stdio.h>

#define STACKSIZE 4

struct Stack
{
  int data[STACKSIZE];
  int sp;
};

void push(struct Stack* stack, int val)
{
  stack->data[stack->sp]=val;
  stack->sp++;

  return;
}

int pop(struct Stack* stack)
{
  int val;

  stack->sp--;
  val=stack->data[stack->sp];

  return val;
}

void init_stack(struct Stack* stack)
{
  stack->sp = 0;
  return;
}

void print_stack(struct Stack* stack)
{
  int i;

  printf("[ ");

  for(i=0; i<stack->sp; i++){
    printf("%d ", stack->data[i]);
  }

  printf("]\n");

  return;
}

int main(void)
{
  int n1,n2;
  
  struct Stack stack;
  init_stack(&stack);

  print_stack(&stack);
  push(&stack,3); print_stack(&stack);
  push(&stack,1); print_stack(&stack);
  push(&stack,4); print_stack(&stack);
  push(&stack,7); print_stack(&stack);
  n1 = pop(&stack); print_stack(&stack);
  n2 = pop(&stack); print_stack(&stack);
  push(&stack,5); print_stack(&stack);

  printf("%d,%d\n",n1,n2);
  
  return 0;
}
