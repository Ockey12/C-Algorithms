#include<stdio.h>
#include<string.h>

#define N 8

typedef struct 
{
  int size;
  char* data[N];
} HashTable;

int search(HashTable* htbl, char str[])
{
  int i,hash;

  for(i = 0; i < htbl->size; i++){

    hash=(strlen(str)+i)%htbl->size;

    if(htbl->data[hash] == NULL){
      return -1;
    }

    if(strcmp(htbl->data[hash],str) == 0){
      return hash;
    }

  }

  return -1;
}

void insert(HashTable* htbl, char str[])
{
  int i,hash;

  if (search(htbl, str) >= 0) {
    return;
  }

  for(i = 0; i < htbl->size; i++){
    hash=(strlen(str)+i)%htbl->size;
    if (htbl->data[hash] == NULL || strcmp(htbl->data[hash], "") == 0) {
      htbl->data[hash] = str;
      return;
    }
  }

  printf("Hash table is full.\n");
  return;
}

void delete(HashTable* htbl, char str[])
{
  int idx;

  idx=search(htbl,str);

  if(idx<0){
    return;
  }else{
    htbl->data[idx]="";
  }

  return;
}

void print_hash(HashTable* htbl)
{
  int i;
  for(i = 0; i < htbl->size; i++){
    if(htbl->data[i] == NULL){
      printf("NULL,");
    } else if(strcmp(htbl->data[i],"") == 0){
      printf("deleted,");
    } else {
      printf("%s,",htbl->data[i]);
    }
  }
  printf("\n");

  return;
}

int main(void)
{
  HashTable hash = {N};
  int ans;
  char str1[] = "serval";
  char str2[] = "cheetah";
  char str3[] = "leopard";
  char str4[] = "jaguar";

  print_hash(&hash);

  insert(&hash,str1);
  insert(&hash,str2);
  insert(&hash,str3);
  insert(&hash,str4);

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
