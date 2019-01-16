#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <shadow.h>

/*
 * Print information from the password entry
 * about the user name given as argv[1].
 */

int main( int argc, char** argv ) 
{
    struct spwd* sp;
    
	if (argc < 2) {
   		//printf("%s username \n", argv[0]);
		printf("USAGE: %s username\n\n ", argv[0]);
        return(EXIT_FAILURE);
	}

    if( ( sp = getspnam( argv[1] ) ) == (struct spwd*)0) {
    	fprintf( stderr, "getspnam: unknown %s\n", argv[1] );
      	return( EXIT_FAILURE );
    }
    printf( "Login Name: %s\n", sp->sp_namp );
    printf( "Password: %s\n", sp->sp_pwdp );
    printf( "Last Password Changed: %ld\n", sp->sp_lstchg );
    printf( "Days Until Change Allowed: %ld\n", sp->sp_min );
    printf( "Days Before Change Required: %ld\n", sp->sp_max );
    printf( "Days Warning for Expiration: %ld\n", sp->sp_warn );
    printf( "Days Before Account Inactive: %ld\n", sp->sp_inact );
    printf( "Date When Account Expires: %ld\n", sp->sp_expire );
    return( EXIT_SUCCESS );
}
