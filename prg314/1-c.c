#include<stdio.h>

#define N 16

int main(void)
{
  double x[N];
  int i=0, n;

  FILE* file = fopen("data1403.txt", "r");

  while(fscanf(file, "%lf", &x[i]) != EOF){
    i++;
  }

  fclose(file);

  n = i;
	
  for (i = n - 1; i >= 0; i--) {
    printf("%f\n", x[i]);
  }

  return 0;
}
