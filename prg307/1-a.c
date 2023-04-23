#include<stdio.h>

#define NAME 8

struct Record
{
  char name[NAME];
  int min;
  int sec;
};

void doping(struct Record record)
{
  record.sec = record.sec - 10;
  return;
}

void training(struct Record* recordp)
{
  recordp->sec = recordp->sec - 10;
  return;
}

int main(void)
{
  struct Record record = {"Sato",7,48};
  struct Record* recordp;

  printf("%d:%d\n",record.min,record.sec);

  doping(record);
  printf("%d:%d\n",record.min,record.sec);

  recordp = &record;
  training(recordp);
  printf("%d:%d\n",record.min,record.sec);

  training(&record);
  printf("%d:%d\n",record.min,record.sec);

  return 0;
}
