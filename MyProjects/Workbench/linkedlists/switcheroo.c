#include <stdio.h>  
#include <string.h>

int main() {  

	int answer;  
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
           	printf("Your answer was invalid. \n");  
	}
   	return 0;  
} 

