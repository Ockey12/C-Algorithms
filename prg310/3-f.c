#include<stdio.h>
#include<stdlib.h>

#define QSIZE 4

struct Queue
{
  int max;
  int* data;
  int front;
  int rear;
};

void enqueue(struct Queue* q, int val)
{
  int old_max;
  int* new_data;
  int i;

  if(q->front == (q->rear+1)%q->max){
    old_max=q->max;
    q->max=old_max*2;
    printf("grow\n");

    new_data=calloc(q->max,sizeof(int));
    if(q == NULL){
      printf("ERROR\n");
      exit(EXIT_FAILURE);
    }
   
    for(i=0; i<old_max-1; i++){
      new_data[i]=q->data[(q->front + i) % old_max];
    }
    free(q->data);

    q->data=new_data;
    q->front=0;
    q->rear=old_max-1;

  }

  q->data[q->rear]=val;
  q->rear=(q->rear + 1) % q->max;

  return;
}

int dequeue(struct Queue* q)
{
  int val;
  if(q->front == q->rear){
    printf("Queue is empty.\n");
    return -1;
  }
  val = q->data[q->front];
  q->front=(q->front + 1) % q->max;
  return val;
}

void init_queue(struct Queue* q)
{
  q->front = q->rear = 0;
  q->max = QSIZE;
  q->data = calloc(q->max, sizeof(int));
  if(q->data == NULL){
    printf("ERROR\n");
    exit(EXIT_FAILURE);
  }

  return;
}

void print_queue(struct Queue* q)
{
  int i,size;

  size = (q->rear + q->max - q->front) % q->max;

  printf("[ ");
  for(i = 0; i < size; i++){
    printf("%d ", q->data[(q->front + i) % q->max]);
  }
  printf("]\n");

  return;
}

int main(void)
{
  int n1,n2,n3,n4,n5,n6,n7;
  struct Queue q;
  init_queue(&q);

  print_queue(&q);
  enqueue(&q, 101); print_queue(&q);
  n1 = dequeue(&q); print_queue(&q);
  enqueue(&q, 102); print_queue(&q);
  n2 = dequeue(&q); print_queue(&q);
  enqueue(&q, 103); print_queue(&q);
  n3 = dequeue(&q); print_queue(&q);
  enqueue(&q, 104); print_queue(&q);
  enqueue(&q, 105); print_queue(&q);
  n4 = dequeue(&q); print_queue(&q);
  n5 = dequeue(&q); print_queue(&q);
  enqueue(&q, 106); print_queue(&q);
  enqueue(&q, 107); print_queue(&q);
  enqueue(&q, 3); print_queue(&q);
  n6 = dequeue(&q); print_queue(&q);
  n7 = dequeue(&q); print_queue(&q);
  enqueue(&q, 1); print_queue(&q);
  enqueue(&q, 4); print_queue(&q);
  enqueue(&q, 7); print_queue(&q);
  enqueue(&q, 5); print_queue(&q);
  enqueue(&q, 9); print_queue(&q);
  enqueue(&q, 2); print_queue(&q);
  enqueue(&q, 6); print_queue(&q);
  enqueue(&q, 8); print_queue(&q);
  enqueue(&q, 13); print_queue(&q);
  enqueue(&q, 11); print_queue(&q);
  enqueue(&q, 14); print_queue(&q);
  enqueue(&q, 17); print_queue(&q);
  enqueue(&q, 15); print_queue(&q);
  enqueue(&q, 19); print_queue(&q);
  enqueue(&q, 12); print_queue(&q);

  printf("%d,%d,%d,%d,%d,%d,%d\n",n1,n2,n3,n4,n5,n6,n7);

  return 0;
}
