#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>       // imports isalpha(), isdigit(), etc...

// String validation; In the form of:
// [alpha][number][alpha] aka: a3e r2q
int main( void )
{
  // Input string

  char sz[4];

  // Get input

  fgets( sz, sizeof( sz ), stdin );

  // Output input

  printf( "You entered: %s\n", sz );

  // Validate input

  if( isalpha( sz[0] ) && isdigit( sz[1] ) && isalpha( sz[2] ) )
    puts( "Good form" );
  else
    puts( "Bad form, bad!" );

  // Successfully exit

  return 0;
}
