#include <stdio.h>
#include <stdlib.h>

int* read_ints (const char* file_name, int *res)
{
  FILE* file = fopen(file_name, "r");
  int i = 0;

  while (!feof(file))
    {
      fscanf(file, "%d", &res[i]);
      i++;
    }

  return res;
}


int* convert(int n)
{
  int b = 10, t = 0, *res, i;

  while(n % b != n)
    {
      b = b * 10;
      t++;
    }

  res = malloc((t + 2) * sizeof(int));

  res[0] = t;
  for ( i = 1; i <= t + 1; i++)
    {
      b /= 10;
      res[i] = n / b % 10;
    }

  return res;
}

int show(int *res, int len)
{
  int i = 0;

  for (i = 0; i <= len - 1; i++)
    printf("%d\n", res[i]);

  return 0;
}

int show_convert(int *res, int len)
{
  int i;

  for (i = 1; i <= len; i++)
    printf("%d ", res[i]);

  printf("\n");

  return 0;
}

int judge(int *res)
{
  int flag = 0, i = 0;;

  while(res[i] != -1 && i <= 9)
    i++;

  if (i == 10)
    flag = 1;

  return flag;
}

int show_indi(int *indi)
{
  int i = 0;

  for (i = 0; i <= 9; i++)
    printf("%d ", indi[i]);

  printf("\n");

  return 0;
}

int process(int N)
{
  int indi[10], i = 0, *res, j, t = 1, tmp = N;
  
  if (N != 0)
    {
      for (i = 0; i <= 9; i++)
	indi[i] = -1;
      
      while(judge(indi) != 1)
	{
	  res = convert(N);


	  for (j = 1; j <= res[0] + 1; j++)
	    {
	      if (indi[res[j]] == -1)
		indi[res[j]] = res[j];
	    }

	  t++;
	  N = t * tmp;
	}
    }

  return N - tmp;
}


int main(int argc, char *argv[])
{
  int *res, i = 0;
  
  res = (int*)malloc(101 * sizeof(int));

  res = read_ints("A-small-practice.in", res);

  for (i = 1 ; i <= 100; i++)
    {
      if (res[i] == 0)
	printf("Case #%d: INSOMNIA\n", i);
      else
	printf("Case #%d: %d\n", i, process(res[i]));
    }

  return 0;
}
