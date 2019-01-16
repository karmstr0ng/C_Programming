/* example one, a simple continue statement */
#include <stdio.h>
#include <ctype.h>

main()
{
	int     valid_input;    /* when 1, data is valid and loop is exited */
	char    user_input;     /* handles user input, single character menu choice */

	valid_input = 0;
	while( valid_input == 0 ) {
		printf("Continue (Y/N)?\n");
		scanf("  %c", &user_input );
		//user_input = toupper( user_input );
		if((user_input == 'Y') || (user_input == 'N') )  valid_input = 1;
		else  printf("\007Error: Invalid choice\n");
	}
}

