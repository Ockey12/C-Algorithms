#include<stdio.h>

#define QSIZE 4

struct Queue
{
  int data[QSIZE];
  int front;
  int rear;
};

void enqueue(struct Queue* q, int val)
{
  if(q->front == (q->rear+1)%QSIZE){
    printf("Queue is full.\n");
    return;
  }

  q->data[q->rear] = val;
  q->rear=(q->rear + 1) % QSIZE;
  return;
}

int dequeue(struct Queue* q)
{
  int val;

  if(q->rear == q->front){
    printf("Queue is empty.\n");
    return -1;
  }

  val = q->data[q->front];
  q->front=(q->front + 1) % QSIZE;
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

  size = (q->rear + QSIZE - q->front) % QSIZE;

  printf("[ ");
  for(i = 0; i < size; i++){
    printf("%d ", q->data[(q->front + i) % QSIZE]);
  }
  printf("]\n");

  return;
}

int main(void)
{
  int n1,n2,n3;
  struct Queue q;
  init_queue(&q);

  print_queue(&q);
  enqueue(&q, 3); print_queue(&q);
  n1 = dequeue(&q); print_queue(&q);
  n2 = dequeue(&q); print_queue(&q);
  enqueue(&q, 3); print_queue(&q);
  enqueue(&q, 7); print_queue(&q);
  enqueue(&q, 5); print_queue(&q);
  enqueue(&q, 9); print_queue(&q);
  n3 = dequeue(&q); print_queue(&q);
  enqueue(&q, 2); print_queue(&q);

  printf("%d,%d,%d\n",n1,n2,n3);

  return 0;
}
