#include<stdio.h>
#include<string.h>
#include "ex3lib11.h"

#define N 4

typedef struct 
{
  int size;
  LNODE head[N];
} HashTable;

int search(HashTable* htbl, char str[])
{
  int hash = strlen(str)%htbl->size;
  LNODE* tmp = LL_search_val(&htbl->head[hash],str);

  if(tmp==NULL){
    return 0;
  }else{
    return 1;
  }
}

void insert(HashTable* htbl, char str[])
{
  int hash = strlen(str)%htbl->size;

  if(search(htbl, str)==1){
    return;
  }

  LL_insert_next(&htbl->head[hash],str);

  return;
}

void delete(HashTable* htbl, char str[])
{
  int hash = strlen(str)%htbl->size;
  
  LL_delete_val(&htbl->head[hash],str);

  return;
}

void print_hash(HashTable* htbl)
{
  int i;
  for(i = 0; i < htbl->size; i++){
    printf("%d:",i);
    LL_print(&htbl->head[i]);
  }
  printf("\n");
  return;
}

void HTBL_init(HashTable* htbl)
{
  int i;
  for(i = 0; i < htbl->size; i++){
    LL_init(&htbl->head[i]);
  }
  return;
}


int main(void)
{
  HashTable hash = {N};
  int ans;

  HTBL_init(&hash);
  
  print_hash(&hash);

  insert(&hash,"serval");
  insert(&hash,"cheetah");
  insert(&hash,"leopard");
  insert(&hash,"jaguar");

  print_hash(&hash);

  ans = search(&hash,"jaguar");
  printf("%d\n",ans);
  ans = search(&hash,"cat");
  printf("%d\n",ans);
  ans = search(&hash,"panther");
  printf("%d\n",ans);

  delete(&hash,"leopard");

  print_hash(&hash);
  insert(&hash,"jaguar");
  print_hash(&hash);
  delete(&hash,"panther");
  print_hash(&hash);
  insert(&hash,"cougar");
  print_hash(&hash);
  delete(&hash,"jaguar");
  print_hash(&hash);

  return 0;
}
