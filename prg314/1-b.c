#include<stdio.h>

#define N 8
#define M 16

typedef struct 
{
  char name[M];
  int hour;
  int min;
  int sec;
} RECORD;

int main(void)
{
  RECORD a[N];
  int i, n;

  FILE* file=fopen("data1402.txt","r");

  fscanf(file,"%d",&n);
  for(i=0; i<n; i++){
    fscanf(file,"%s %d %d %d",a[i].name,&a[i].hour,&a[i].min,&a[i].sec);
  }

  fclose(file);

  n=i;

  for(i=n-1; i>=0; i--){
    printf("%s(%d:%d:%d)\n",a[i].name,a[i].hour,a[i].min,a[i].sec);
  }

  return 0;
}
