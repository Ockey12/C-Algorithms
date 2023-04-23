#include<stdio.h>
#include "ex3lib11.h"

int main(void)
{
  LNODE node0;
  LNODE* head = &node0;
  LNODE* tmp;
  char *c1,*c2;

  char str1[] = "rat";
  char str2[] = "ox";
  char str3[] = "tiger";
  char str4[] = "hare";

  LL_init(head);
  LL_insert_next(head,str1);
  LL_insert_next(head,str2);
  LL_print(head);
  LL_insert_next(head,str3);
  LL_print(head);

  tmp = LL_search_val(head,"hare");
  if(tmp == NULL){
    c1 = "NULL";
  } else {
    c1 = tmp->data;
  }

  LL_delete_val(head,"rat");
  LL_insert_next(head,str4);
 
  tmp=LL_search_val(head,"hare");
  if(tmp == NULL){
    c2 = "NULL";
  } else {
    c2 = tmp->data;
  }

  LL_print(head);

  printf("%s,%s\n",c1,c2);

  return 0;
}
