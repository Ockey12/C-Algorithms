#include<stdio.h>
#include<string.h>

#define M 16
#define N 8

typedef struct _record
{
  char name[M];
  int hour;
  int min;
  int sec;
} RECORD;

void swap(RECORD* a[], int m, int n)
{
  
  RECORD *re;
  re=a[m];
  a[m]=a[n];
  a[n]=re;

  return;
}

void busort(RECORD* a[], int n)
{
  int i, j;
  int n2=n-1;

  for(i=1; i<n; i++){
    for(j=0; j<n2; j++){
      if((a[j]->hour*3600+a[j]->min*60+a[j]->sec > a[j+1]->hour*3600+a[j+1]->min*60+a[j+1]->sec) || (a[j]->hour*3600+a[j]->min*60+a[j]->sec == a[j+1]->hour*3600+a[j+1]->min*60+a[j+1]->sec && strcmp(a[j]->name,a[j+1]->name)>0)){
        swap(a,j,j+1);
      }
    }
    n2--;
  }

  return;
}

void print_records(RECORD* a[], int n)
{
  int i;

  for(i=0; i<n; i++){
    printf("%s(%d:%d:%d),", a[i]->name, a[i]->hour, a[i]->min, a[i]->sec);
  }
  printf("\n");
  
  return;
}

int main(void)
{
  RECORD record[] = {{"Sato", 2, 10, 5}, {"Tanaka", 2, 1, 38}, {"Suzuki", 1, 58, 24}, {"Ito", 2, 1, 38}, {"Takahashi", 2, 1, 38}};

  RECORD* recordp[N];
  int n = sizeof(record) / sizeof(record[0]);
  int i;

  for (i = 0; i < n; i++){
    recordp[i] = &record[i];
  }

  print_records(recordp, n);

  busort(recordp, n);
	
  print_records(recordp, n);

  return 0;
}
