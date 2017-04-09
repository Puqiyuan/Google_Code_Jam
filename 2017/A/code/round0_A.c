#include <stdio.h>
#include <stdlib.h>


int store(char **res, const char *file_name)
{
  int i = 0;;

  FILE *file = fopen(file_name, "r");

  while (!feof(file))
    {
      fgets(res[i], 102, file);
      i++;
    }

  return 0;
}


int show_input(char **res)
{
  int i;

  for (i = 0; i <= 100; i++)
    printf("%s", res[i]);


  return 0;
}





int main(int argc, char *argv[])
{
  int i;
  char **res;
  res = (char**)malloc(101 * sizeof(char*));

  for (i = 0; i <= 100; i++)
    res[i] = (char*)malloc(101 * sizeof(char));

  store(res, "A-small-practice.in");
  show_input(res);

  
  return 0;
}
