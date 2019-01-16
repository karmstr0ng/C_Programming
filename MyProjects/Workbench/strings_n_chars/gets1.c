#include <stdio.h>

int main()
{
  char my_string[500];
  printf("Type something.\n");
  gets(my_string);
  printf ("You typed: %s\n", my_string);

  return 0;
}
