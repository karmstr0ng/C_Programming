#include <stdio.h>
#include <string.h>
#define BIGBUF 3000

int main ( ) {
    char buff[BUFSIZ];          // the input line
    char newbuff[BUFSIZ];       // the results of any editing
    char findme[]                               = "PermitRootLogin";
    char replacewith[]                  = "PermitRootLogin no\n";
	char * strg;
    FILE *in, *out;

    in = fopen( "sshd_config", "r" );
    out= fopen( "new.txt", "w" );

    while ( fgets( buff, BUFSIZ, in ) != NULL ) {
        if ( strstr( buff, findme ) != NULL ) {
			strg = buff;
            fputs ( buff, stdout );
			printf ( "first letter is: \n", strg[1] );

        }
    }

    fclose( in );
    fclose( out );
    return 0;
}
