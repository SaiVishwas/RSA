#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"
#include<string.h>
#include<stdlib.h>
void encrypt(char *a,char *b)  // n , e
{


int i =0 ;

char ch[1025];
char num[5] ; 
ch[0]='\0';


FILE *ptr_file;
    		char buf[1000];
FILE *fptr;
   fptr=fopen("str_to_int.txt","w");

    		ptr_file =fopen("input.txt","r");
    		if (!ptr_file)
        		printf("File not found");

int c;
i=0;
while(c=fgetc(ptr_file))


{

++i;

    if(c == EOF) break;

else 

fprintf(fptr,"%d",c+100);   // converting to 3 digit code
if(i==50)
{
fprintf(fptr,"%s","\n");    // 50 characters per line (each line will be encrypted at once)
i=0;
}
}

		fclose(ptr_file); 
   fclose(fptr);  


enc_caller(a,b);   // passing on n , e (not used)
}
 
