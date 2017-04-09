#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int* read_ints (const char* file_name,long int *res)
{
  FILE* file = fopen(file_name, "r");
  int i = 0;

  while (!feof(file))
    {
      fscanf(file, "%ld", &res[i]);
      i++;
    }

  return res;
}


int show(long int *res, int len)
{
  int i = 0;

  for (i = 1; i <= len; i++)
    printf("%ld\n", res[i]);

  return 0;
}


char* convert(long int d, char *res, int len)
{
  snprintf( res, len + 1, "%ld", d );

  return res;
}


int show_con(char *res)
{
  int len = strlen(res), i;

  for ( i = 0; i <= len - 1; i++)
    printf("%c ", res[i]);

  printf("\n");

  return 0;
}


int judge(char *str)
{
  int flag = 0;
  int len = strlen(str), i;

  for (i = 0; i <= len - 2; i++)
    {
      if (str[i] <= str[i + 1])
	continue;
    
      else
	break;
    }

  if (i == len - 1)
    flag = 1;

  return flag;
}


int main(int argc, char *argv[])
{
  long int *res, tmp;
  int i, flag, LEN; 

  
  
  res = (long int*)malloc(101 * sizeof(long int));

  res = read_ints("B-small-attempt1.in", res);

  LEN = res[0];

  for (i = 1; i <= LEN; i++)
    {
      flag = 0;
      for (tmp = res[i]; tmp >= 1; tmp--)
	{
	  int len = snprintf(NULL, 0, "%ld", tmp);
	  char *str = malloc(len + 1);
      
	  convert(tmp, str, len);

	  if (judge(str))
	    {
	      printf("Case #%d: %s\n", i, str);
	      flag = 1;
	    }

	  if (flag)
	    {
	      break;
	    }
	}
    }
  
  return 0;
}
