#include<stdio.h>
#include<stdlib.h>

#define N 8

typedef struct _lnode
{
  int data;
  struct _lnode *next;
} LNODE;

int main(void)
{
  LNODE *nodep1;
  LNODE *nodep2;
  LNODE *nodep3;
  LNODE *pos;

  nodep1 = calloc(1,sizeof(LNODE));
  if(nodep1 == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  nodep1->data = 3;
  nodep1->next = NULL;

  nodep2 = calloc(1,sizeof(LNODE));
  if(nodep2 == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  nodep2->data = 8;
  nodep2->next = NULL;

  nodep1->next = nodep2;

  nodep3 = calloc(1,sizeof(LNODE));
  if(nodep3 == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  nodep3->data = 5;
  nodep3->next = NULL;

  nodep2->next = nodep3;

  pos = nodep1;
  
  while(pos != NULL){
    printf("%d,",pos->data);
    pos = pos->next;
  }
  printf("\n");
  
  nodep2->next=NULL;
  free(nodep3);

  nodep1->next=NULL;
  free(nodep2);
  
  free(nodep1);
  
  return 0;
}
