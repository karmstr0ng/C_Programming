#include <stdio.h>
#include <string.h>
#define BIGBUF 3009

int main ( ) {
    char buff[BUFSIZ];      // the input line
    char newbuff[BUFSIZ];   // the results of any editing
    char findme[] = "PermitRootLogin";
    char replacewith[] = "PermitRootLogin no\n";
    FILE *in, *out;
	
	printf("Choose option : ");

    in = fopen( "sshd_config", "r" );
    out= fopen( "new.txt", "w" );

    while ( fgets( buff, BUFSIZ, in ) != NULL ) {
        if ( strstr( buff, findme ) != NULL ) {
			fgets(newbuff,BUFSIZ,out);
			strcpy(newbuff, replacewith);
        } 
		else {
            // nothing to do - the input line is the output line
            strcpy( newbuff, buff );
        }
		
    	fputs( newbuff, out );
    }
    fclose( in );
    fclose( out );
	
	/* Start file copy code here */

	
    return 0;
}
