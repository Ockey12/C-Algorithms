#include<stdio.h>

int lsearch(int a[], int n, int t)
{
  int i;

  for(i=0; i<n; i++){
    if(a[i] == t){
      return i;
    }
  }

  return -1;

}

int main(void)
{
  int a[16];
  int n = 10, i, ans1, ans2;
  FILE* file;


  file = fopen("data0301.txt", "r");
  for(i=0; i<n; i++){
    fscanf(file, "%d", &a[i]);
  }
  fclose(file);


  ans1 = lsearch(a, n, 10);
  ans2 = lsearch(a, n, 24);

  printf("%d,%d\n", ans1, ans2);

  return 0;
}
