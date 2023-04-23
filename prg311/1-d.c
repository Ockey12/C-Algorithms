#include<stdio.h>
#include"ex3lib11.h"

#define N 4

int main(void)
{
  LNODE head[N];
  int i;

  for(i = 0; i < N; i++){
    LL_init(&head[i]);
  }

  LL_insert_next(&head[3],"rat");
  LL_insert_next(&head[2],"ox");
  LL_insert_next(&head[1],"tiger");
  LL_insert_next(&head[0],"hare");
  LL_insert_next(&head[2],"dragon");

  LL_delete_val(&head[1],"tiger");

  for(i = 0; i < N; i++){
    printf("%d,",i);
    LL_print(&head[i]);
  }

  return 0;
}
