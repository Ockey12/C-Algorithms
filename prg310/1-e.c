#include "LL_stack.c"

#define M 2

int main(void)
{
  LNODE bucket[M] = {{0,NULL}};
  int a[] = {3,7,4,1,5,9,2,6,8};
  int n = sizeof(a) / sizeof(a[0]);
  int i;

  print_array(a, n);

  for(i=0; i<n; i++){
    if(a[i]%2==0){
      push(&bucket[0],a[i]);
    }else{
      push(&bucket[1],a[i]);
    }
  }

  print_stack(&bucket[0]);
  print_stack(&bucket[1]);

  i=n-1;
  while(!empty(&bucket[1])){
    a[i]=pop(&bucket[1]);
    i--;
  }
  while(!empty(&bucket[0])){
    a[i]=pop(&bucket[0]);
    i--;
  }

	
  print_array(a, n);

  return 0;
}
