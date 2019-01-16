#include <stdio.h>
//#include <conio.h>
#include <string.h>
int main(char st[80]) {

  FILE *p;
  char file[80];
  printf("Open File: "/*, &file*/);
  gets(file);
  p = fopen(file, "r");

  if (p) //{
  fgets(st, 60, p);
/*  st[strlen(st)] = 0;
  printf("The data of the file is: %s\n", st);
  getchar();
  } else {
  printf("File does not exist.\n");
  }
*/
  fclose(p);

  return 0;
} 
