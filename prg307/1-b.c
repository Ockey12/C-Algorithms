#include<stdio.h>

#define QSIZE 1024

struct Queue
{
  int data[QSIZE];
  int front;
  int rear;
};

void enqueue(struct Queue* q, int val)
{
  q->data[q->rear]=val;
  q->rear++;

  return;
}

int dequeue(struct Queue* q)
{
  int val;

  val=q->data[q->front];
  q->front++;

  return val;
}

void init_queue(struct Queue* q)
{
  q->front = q->rear = 0;
  return;
}

void print_queue(struct Queue* q)
{
  int i,size;

  size = q->rear - q->front;
  
  printf("[ ");
  for(i = 0; i < size; i++){
    printf("%d ", q->data[q->front + i]);
  }
  printf("]\n");
  return;
}

int main(void)
{
  int n1,n2;
  struct Queue q;
  init_queue(&q);

  print_queue(&q);
  enqueue(&q, 3); print_queue(&q);
  enqueue(&q, 1); print_queue(&q);
  enqueue(&q, 4); print_queue(&q);
  enqueue(&q, 7); print_queue(&q);
  n1 = dequeue(&q); print_queue(&q);
  n2 = dequeue(&q); print_queue(&q);
  enqueue(&q, 5); print_queue(&q);

  printf("%d,%d\n",n1,n2);
  
  return 0;
}
