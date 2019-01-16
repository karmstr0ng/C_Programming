#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    char char_arry[] = "Hello World";
    char* pA;
    char* pB;
    pA = char_arry;
    pB = (char*) malloc(sizeof(char));
    char buffer[100];
    FILE* pFile;

        if (argc != 2){
                printf("Missing arguements ...\n");
                printf("Exiting\n");
                exit(1);
        }
        else if  (!(pFile = fopen(argv[1], "r"))) {
                printf("Cannot open file %s\n", argv[1]);
                printf("Existing ...\n");
                exit(1);
        }
    //pFile = fopen("passwd", "r");
    printf("String: %s", char_arry);

    while (*pA != '\0'){
        printf("\nchar_arry: %c ", *pA);
        if(*pA == 'W')
            printf("---> Found \'W\'");
        *pB++ = *pA++;
    }
    printf("\nNow in reverse");
    while (*pA != 'H'){
        printf("\nchar_arry: %c ", *pA);
        *pB-- = *pA--;
        }
    printf("\nchar_arry: %c \n", *pA);

    if (pFile != NULL) {
        printf("The next word in the file is:\n");
         do {
                printf("%s", buffer);
            }while(fgets(buffer, LINE_MAX, pFile) != NULL) ;
        fclose(pFile);
    }
    return 0;
}
