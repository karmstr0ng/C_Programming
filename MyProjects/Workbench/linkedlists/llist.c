#include <stdlib.h>
#include <stdio.h>

struct node {
	int x;
	struct node *next;
};	

int main() {
	printf("Hello, World!!!\n");

	/* This will be the unchanging first node */
    struct node *root 		= NULL;      
	struct node *second 	= NULL;
	struct node *conductor 	= NULL;

    /* Now root points to a node struct */
    root 		= malloc( sizeof(struct node) ); 
    second 		= malloc( sizeof(struct node) ); 
    conductor 	= malloc( sizeof(struct node) ); 

    /* The node root points to has its next pointer equal to a null pointer 
       set */
    //root->next = 0;  
    /* By using the -> operator, you can modify what the node,
       a pointer, (root in this case) points to. */
    root->x = 5;
	conductor = root;
	
	if ( conductor != 0 ) {
        while ( conductor->next != 0)
        {
            conductor = conductor->next;
			printf("conductor->x is: %d\n", conductor->x);
        }
    }

	conductor->next = malloc( sizeof(struct node) );  

    conductor = conductor->next; 

    if ( conductor == 0 )
    {
        printf( "Out of memory" );
        return 0;
    }
    /* initialize the new memory */
    conductor->next = 0;         
    conductor->x = 42;

	printf("conductor->x is: %d\n", conductor->x);
	printf("conductor->*next is: %d\n", conductor->next);
	printf("root->x is: %d\n", root->x);
	

    return 0;

}
