//Examples of using modify operators
#include <stdio.h>

int main() {
  int x = 10, y = 20, z = 30;

  printf("%d\n%d\n%d\n", x, y, z);

  z = x++ * --y;
  printf("%d\n%d\n%d\n", x, y, z);

}
