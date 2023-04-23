#include<stdio.h>

#define N 16

int main(void)
{
  double x[N];
  int i, n;

  FILE* file = fopen("data1401.txt", "r");

  fscanf(file, "%d", &n);
  for (i = 0; i < n; i++){
    fscanf(file, "%lf", &x[i]);
  }

  fclose(file);

  n = i;
	
  for (i = n - 1; i >= 0; i--) {
    printf("%f\n", x[i]);
  }

  return 0;
}
