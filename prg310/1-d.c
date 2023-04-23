#include "LL_stack.c"

int main(void)
{
  int a[] = {3,7,4,1,5,9,2,6,8};
  int n = sizeof(a) / sizeof(a[0]);
  int a2[] = {19,64,39,26,24,8,25,15};
  int n2 = sizeof(a2) / sizeof(a2[0]);
  int i;
  LNODE node = {0,NULL};
  LNODE* stack = &node;

  print_array(a, n);

  for (i = 0; i < n; i++){
    push(stack, a[i]);
  }

  i = 0;
  while (!empty(stack)) {
    a[i]=pop(stack);
    i++;
  }

  print_array(a, n);
	

  print_array(a2, n2);

  for (i = 0; i < n2; i++){
    push(stack, a2[i]);
  }

  for (i = 0; i < n2; i++){
    a2[i] = 0;
  }

  print_array(a2, n2);

  i = n2-1;
  while (!empty(stack)) {
    a2[i]=pop(stack);
    i--;
  }

  
  print_array(a2, n2);
	
  return 0;
}
