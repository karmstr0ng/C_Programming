#include <stdio.h>

int main() {

	int number = 39;
	int myarray[4] = {4,7,5,10};
	int array_to_array[2][4] = {{9,12,43,3},{4,7,5,10}};
	int *ptr = NULL;
	int *ptr1 = NULL;
	int **pptr = NULL;
	int ***ppptr = NULL;

	ptr = &number;
	ptr1 = myarray;
	pptr = &ptr;
	ppptr = &pptr;


	printf("Hello World\n");

	
	printf("addr of x = %d\n", ptr);
	printf("*ptr = %d\n", *ptr);
	printf("*ptr1 + 3 = %d\n", *(ptr1 + 3));
	printf("*ptr1 + 2 = %d\n", *(ptr1 + 2));
	printf("*ptr1 + 1 = %d\n", *(ptr1 + 1));
    printf("*ptr1 = %d\n", *ptr1);
	printf("*ptr1 = %d\n", *(ptr1));
	printf("**pptr = %d\n", *pptr);
	printf("***ppptr = %d\n", ***ppptr);
//	printf("***ppptr = %d\n", **ppptr);
	printf("myarray[1] = %d\n", myarray[1]);


	return(0);
}
