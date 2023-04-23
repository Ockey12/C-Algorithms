#include "LL_stack2.c"

#define M 'z' - 'a' + 1

int main(void)
{
  LNODE bucket[M] = {{NULL,NULL}};
  char* a[] = {"ape", "ewe", "dog", "hog", "bat", "cat", "rat", "fox", "cow"};
  int n = sizeof(a) / sizeof(a[0]);
  int i,j,k;

  print_array(a, n);

  k = 0;
  
  for(i=0; i<n; i++){
    push(&bucket[a[i][k]-'a'],a[i]);
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
