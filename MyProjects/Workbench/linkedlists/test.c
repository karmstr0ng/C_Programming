#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	static const char stringToSearch[] 	= "PermitRootLogin";
	static const char enableRootLogin[] 	= "PermitRootLogin yes";
	static const char disableRootLogin[] 	= "PermitRootLogin no";
	static const char fileName[] 		= "sshd_config";
	char line [128];
	char *p;
	FILE *fp = fopen (fileName, "r");
	int answer;

	/*if (argc != 2) {
		printf("\nUsage: %s [enable/disable] \n\n", argv[0]);
		exit(1);
	}*/

	if (fp == NULL){
		printf("Can't open file %s \n", fileName);
	}
	else{
		printf ("File name is %s \n", fileName);
	}

	while ( fgets ( line, sizeof line, fp ) != NULL ) { /* read a line */
		//fputs ( line, stdout ); /* write the line */  
		if (strstr(line, stringToSearch)) {
			printf("found match \n");
			break;
		}
	}

    printf("Enable or Disablei SSH Root Login by entering 1 to enable Root Login or 2 to disable Root Login:\n");
    scanf("%d", &answer);
    switch (answer) {
        case 1:
            printf("SSH Root Login Enabled\n");
            break;
        case 0:
            printf("SSH Root login Disabled\n");
            break;
        default:
            printf("Your answer was invalid.\n");
            printf("No changes were made to the file.\n");
            printf("Quitting program.\n");
    }
	
	if (fclose(fp) != 0) {
		printf ("Error in closing file %s \n", fileName);		
		exit(1);	
	}
	return 0;
}
