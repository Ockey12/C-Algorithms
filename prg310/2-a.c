#include "LL_stack.c"

#define M 10

int main(void)
{
  LNODE bucket[M] = {{0}};
  int a[] = {314, 159, 265, 358, 979, 323, 846, 264, 338, 327, 950, 288};
  int n = sizeof(a) / sizeof(a[0]);
  int i,j,k;

  print_array(a, n);

  k = 1*M;

  for(i=0; i<n; i++){
    push(&bucket[(a[i]/k)%M],a[i]);
  }

  j=n-1;
  for(i=M-1; i>=0; i--){
    while(!empty(&bucket[i])){
      a[j]=pop(&bucket[i]);
      j--;
    }
  }


  print_array(a, n);

  return 0;
}
