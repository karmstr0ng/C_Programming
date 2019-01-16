#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
 char string[]="string to search";
 char   test[]="sear";
 if (strstr(string, test)) puts("String found");

}
