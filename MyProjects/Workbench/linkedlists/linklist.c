#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};	

int main() {

	int num;
	struct node* test;
	//test = malloc(sizeof(struct node));
	BuildOneTwoThree();
	//  num = Length();	

    return 0;
}

/*
Build the list {1, 2, 3} in the heap and store
its head pointer in a local stack variable.
Returns the head pointer to the caller.
*/
struct node* BuildOneTwoThree() {
	struct node* head	= NULL;
	struct node* second = NULL;
	struct node* third	= NULL;

	head	= malloc(sizeof(struct node)); // allocate 3 nodes in the heap
	second	= malloc(sizeof(struct node));
	third	= malloc(sizeof(struct node));

	head->data = 1; // setup first node
	head->next = second; // note: pointer assignment rule

	second->data = 2; // setup second node
	second->next = third;

	third->data = 3; // setup third link
	third->next = NULL;

	// At this point, the linked list referenced by "head"
	// matches the list in the drawing.
	return head;
}

/*
Given a linked list head pointer, compute
and return the number of nodes in the list.
*/
int Length(struct node* head) {
	struct node* current = head;
	int count = 0;
	while (current != NULL) {
	count++;
	current = current->next;
	}
	return count;
}
