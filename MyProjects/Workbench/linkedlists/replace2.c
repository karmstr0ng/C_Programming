#include<stdio.h>
#include<string.h>
#include<conio.h>

void main()
{
	FILE *fp;
	int i=0,len_string;
	char SearchText[]="Hello"; /* You can replace this text */
	char ReplaceText[]="Help"; /*You can also replace this text. */ 
	char temp[30];
	fp=fopen("filename","a+");
	rewind(fp); /* for going to start of file. */
	if(fp==NULL) 
	{
		printf("File couldn't be opened ");
		exit(0);
	}
	len_string=strlen(SearchText);
	while(1)
	{
		for(i=0;i<len_string;i++) temp[i]=fgetc(fp);
		temp[i+1]=NULL;
		if(stricmp(SearchText,temp)==0) /* the stricmp() is used for comparing both string. */
		{
			fprintf(fp,"%s ",ReplaceText);
			fclose(fp);
			exit(1);
		} 
		fseek(fp,-(len_string-1),1);
	}
	fclose(fp);
} 


