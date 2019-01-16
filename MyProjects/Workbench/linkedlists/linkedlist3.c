#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 80

struct NODE {
 int number;
 char username[80];
 struct NODE *next;
};

int  search_value(struct NODE *llist, int num);
void append_node(struct NODE *llist, int num, char uname[MAX]);
void display_list(struct NODE *llist);
void delete_node(struct NODE *llist, int num);
const char *rec_file 	= "records.cdb";
const char *temp_file 	= "cdb.tmp";

int main(void) {
 char uname[MAX];
 int num = 0;
 int input = 1;
 int retval = 0;
 struct NODE *llist;
   
 llist = (struct NODE *)malloc(sizeof(struct NODE));
 llist->number = 0;
 llist->next = NULL;
   
 while(input != 0) {
  printf("\n-- Menu Selection --\n");
  printf("0) Quit\n");
  printf("1) Insert\n");
  printf("2) Delete\n");
  printf("3) Search\n");
  printf("4) Display\n");
  scanf("%d", &input);

  switch(input) {
   case 0: 
   default:
    printf("Goodbye ...\n");
    input = 0;
    break;
   case 1:
    printf("Your choice: `Insertion'\n");
    printf("Enter the value which should be inserted: ");
    scanf("%d", &num);
    printf("Enter username: \n");
	//fflush(stdin);
	getchar();
	fgets(uname, MAX, stdin);
	printf ("You typed: %s", uname);
    append_node(llist, num, uname);
    break;
   case 2:
    printf("Your choice: `Deletion'\n");
    printf("Enter the value which should be deleted: ");
    scanf("%d", &num);
    delete_node(llist, num);
    break;
   case 3:
    printf("Your choice: `Search'\n");
    printf("Enter the value you want to find: ");
    scanf("%d", &num);
    if((retval = search_value(llist, num)) == -1)
     printf("Value `%d' not found\n", num);
    else
     printf("Value `%d' located at position `%d'\n", num, retval);
    break;
   case 4:
    printf("You choice: `Display'\n");
    display_list(llist);
    break;
   } /* switch */
  } /* while */

 free(llist);
 return(0);
}

void display_list(struct NODE *llist) {
 while(llist->next != NULL) {
  printf("%-10d %s", llist->number, llist->username);
  llist = llist->next;
 }

 printf("%-10d %s", llist->number, llist->username);
}

void append_node(struct NODE *llist, int num, char uname[]) {
 while(llist->next != NULL)
  llist = llist->next;

 llist->next = (struct NODE *)malloc(sizeof(struct NODE));
 llist->next->number = num;
 strcpy(llist->next->username,uname);
 llist->next->next = NULL;
 FILE *fp = fopen(rec_file, "a");
 if (!fp) {
    printf("cannot open database file");
    }
    else {
        fprintf(fp, "%d:%s",llist->next->number,llist->next->username);
        fclose(fp);
    }
}

void delete_node(struct NODE *llist, int num) {
 FILE *fp, *temp_fp;
 struct NODE *temp;
 temp = (struct NODE *)malloc(sizeof(struct NODE));

 if(llist->number == num) {
  /* remove the node */
  temp = llist->next;
  free(llist);
  llist = temp;
  fp = fopen(rec_file, "r");
  if (fp == (FILE *)NULL) return;
  temp_fp = fopen(temp_file, "w");
 } else {
  while(llist->next->number != num)
   llist = llist->next;
   fprintf(temp_fp,"%d:%s",llist->next->number,llist->next->username);

  temp = llist->next->next;
  free(llist->next);
  llist->next = temp;
 }   
  fclose(fp);
  fclose(temp_fp);
  unlink(rec_file);
  rename(temp_file, rec_file);
}

int search_value(struct NODE *llist, int num) {
 int retval = -1;
 int i = 1;

 while(llist->next != NULL) {
  if(llist->next->number == num)
   return i;
  else
   i++;

  llist = llist->next;
 }

 return retval;
}

