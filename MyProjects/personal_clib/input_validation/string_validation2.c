#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
 
 
void getLine(char**);
int validate(char*);
 
int main ( void )
{
   char* text = NULL;
    
   printf("Enter a string: ");
   getLine(&text);
 
   printf("%s - %s \n", text, validate(text) ? "yes" : "no");
 
   return 0;
}
void getLine(char** message) {
 
    int ch, len = 0;
 
    while((ch = getchar()) != '\n') { //check for end of line
        *message = (char*)realloc(*message, len+1); //increase inputString by 1 char
        if(*message == NULL) {
            puts("Error allocating memory");
            exit(1);
        }
        (*message)[len++] = ch;
    }
    (*message)[len] = '\0'; //add end token
}
int validate(char* s) {
	int i;
 
    for(i =0; i < strlen(s); i++) {
 
        if(!isalpha(s[i]))
            return 0;
    }
 
    return 1;
}
