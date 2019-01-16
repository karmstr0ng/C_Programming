/*Program to read in text file and store data in a string*/
#include<stdio.h>

int main()
{
	/*declare and initialise variable*/
    char message[100];
    int i=0;
    FILE *file_in;
    file_in=fopen("text.txt", "r");
    /*stores and prints the data from the string*/
    while (1) {
		fscanf(file_in,"%s", message);
		
    	printf("%s\n", message);
	}
    return 0;
}
