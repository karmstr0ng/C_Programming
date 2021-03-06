#include <stdio.h> 
#include <stdlib.h>   
int main ( void ) {   
	char buf[BUFSIZ];   
	FILE *in = fopen ( "sshd_config", "r" );     

	if ( in == NULL ) {
		 fprintf ( stderr, "Couldn't open file");
		return EXIT_FAILURE;   
	}

	if (fgets ( buf, sizeof buf, in ) != NULL) ;
	fputs ( buf, stdout);

	printf ( "The last line is \"%s\"\n", buf );   
	printf ( "The first character of the last line is '%c'\n", buf[0] );     
	if (buf[0] == '#' || buf[0] != 'P')
		printf( "Dropping this line\n" );

	return 0; 
} 
