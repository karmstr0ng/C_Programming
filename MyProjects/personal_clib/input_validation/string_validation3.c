#include <stdio.h>
#include <ctype.h>
 
int main()
{
 
    char name[21];
 
    printf("Please enter your name : ");
    scanf("%d", (int*) name);
     
	if( isalpha(name) == 0)
	printf("Invalid entry! please enter letters only.");
//	else
//	printf("Welcome %s\n", name);
	 
	return 0;
	 
}
