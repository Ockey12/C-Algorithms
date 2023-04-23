#include<stdio.h>
#include<string.h>

#define N 4

typedef struct 
{
  int size;
  char* data[N];
} HashTable;

int search(HashTable* htbl, char str[])
{
  int hash;

  hash=strlen(str)%htbl->size;

  if(htbl->data[hash] == NULL){
    return -1;
  }

  if(strcmp(htbl->data[hash],str) == 0){
    return hash;
  }

  return -1;
}

void insert(HashTable* htbl, char str[])
{
  int hash;

  if (search(htbl, str) >= 0) {
    return;
  }

  hash = strlen(str) % htbl->size;

  if (htbl->data[hash] == NULL || strcmp(htbl->data[hash], "") == 0) {
    htbl->data[hash] = str;
    return;
  }

  printf("Illegal data error.\n");
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
      printf("Empty,");
    } else if(strcmp(htbl->data[i],"") == 0){
      printf("Deleted,");
    } else {
      printf("%s,",htbl->data[i]);
    }
  }
  printf("\n");

  return;
}

int main(void)
{
  HashTable htbl = {N};
  int ans;
  char str1[] = "wolf";
  char str2[] = "raccoon";

  print_hash(&htbl);

  insert(&htbl,str1);
  insert(&htbl,str2);

  print_hash(&htbl);

  ans = search(&htbl,"fox");
  printf("%d\n",ans);
  ans = search(&htbl,"raccoon");
  printf("%d\n",ans);

  delete(&htbl,"raccoon");

  insert(&htbl,"wolf");
  insert(&htbl,"racoon");

  print_hash(&htbl);
  insert(&htbl,"fox");
  print_hash(&htbl);

  return 0;
}
