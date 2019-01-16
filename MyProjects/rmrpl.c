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
	//fscanf();

    in = fopen( "sshd_config", "r" );
    out= fopen( "new.txt", "w" );

    while ( fgets( buff, BUFSIZ, in ) != NULL ) {
        if ( strstr( buff, findme ) != NULL ) {
			fgets(newbuff,BUFSIZ,out);
			strcpy(newbuff, replacewith);
//			fputs( newbuff, stdout );
			//fputc( '\n',out );
            // do 1 or more replacements
            // the result should be placed in newbuff
            // just watch you dont overflow newbuff...
        } 
		else {
            // nothing to do - the input line is the output line
            strcpy( newbuff, buff );
        }
		
    	fputs( newbuff, out );
    }
	//fprintf(out, "\n");

    fclose( in );
    fclose( out );

//	fflush(newbuff);
    return 0;
}
