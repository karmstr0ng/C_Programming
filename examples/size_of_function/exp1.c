// sizeof() function examples
#include <stdio.h>
#include <limits.h>


int main() {
  char  c;
  short s;
  int   d;
  float f;
  

  printf("size of char:  %d byte(s)\n", sizeof(c));
  printf("size of short: %d byte(s)\n", sizeof(s));
  printf("size of int:   %d byte(s)\n", sizeof(d));
  printf("size of int:   %d byte(s)\n", sizeof(int));
  printf("size of float: %d byte(s)\n", sizeof(f));
  printf("size of float: %d byte(s)\n", sizeof(float));


  printf("signed short min value: %d\n", SHRT_MIN);
  printf("signed short max value: %d\n", SHRT_MAX);
  printf("unsigned short max value: %u\n", USHRT_MAX);

  return (0);
}






