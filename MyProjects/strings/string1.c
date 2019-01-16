#include <stdio.h>
#include <string.h>

int main() {
	char S1[256];

	puts("enter text: ");
	scanf("%s",S1); 
        #ifdef DEBUG
	printf("printing line %d at "__TIME__" "__DATE__"\n", __LINE__);
	#endif
	printf("you entered %s\n", S1);	
	return 0;
}
