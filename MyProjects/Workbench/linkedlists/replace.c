#include <stdio.h> 
#include <string.h>   

int main ( ) {

	#define BUFFSIZE 32
    char buff[BUFFSIZE];      // the input line
    char newbuff[BUFFSIZE];   // the results of any editing 
    char findme[] = "hello";     
	char replacewith[] = "world";     

	FILE *in, *out;       
	in = fopen( "file.txt", "r" );     
	out= fopen( "new.txt", "w" );       

	while ( fgets( buff, BUFSIZ, in ) != NULL ) {
		if ( strstr( buff, findme ) != NULL ) {            
	
	// do 1 or more replacements             
	// the result should be placed in newbuff             
	// just watch you dont overflow newbuff...         
		} 
		else {             // nothing to do - the input line is the output line             
			strcpy( newbuff, buff );         
		}         fputs( newbuff, out );     
	}

	fclose( in );     
	fclose( out );     

	return 0; 
}

