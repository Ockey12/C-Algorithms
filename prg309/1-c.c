#include<stdio.h>
#include<stdlib.h>

#define N 8

typedef struct _dnode
{
  int data;
  struct _dnode *next;
  struct _dnode *prev;
} DNODE;

int main(void)
{
  DNODE *nodep1;
  DNODE *nodep2;
  DNODE *nodep3;

  nodep1 = calloc(1,sizeof(DNODE));
  if(nodep1 == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }

  nodep2 = calloc(1,sizeof(DNODE));
  if(nodep2 == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }

  nodep3 = calloc(1,sizeof(DNODE));
  if(nodep3 == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }
  
  nodep1->data = 3;

  nodep2->data = 8;
  nodep3->data = 5;

  nodep1->next = nodep2;
  nodep2->prev = nodep1;

  nodep2->next = nodep3;
  nodep3->prev = nodep2;

  nodep3->next = nodep1;
  nodep1->prev = nodep3;

  printf("%d,",nodep1->next->data);
  printf("%d,",nodep1->next->prev->data);
  printf("%d\n",nodep1->prev->data);

  nodep1->next=NULL;
  nodep1->prev=NULL;
  nodep2->next=NULL;
  nodep2->prev=NULL;
  nodep3->next=NULL;
  nodep3->prev=NULL;

  free(nodep1);
  free(nodep2);
  free(nodep3);

  return 0;
}
