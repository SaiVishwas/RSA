#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"

void decrypt(char *a,char *b)   // n  ,  d
{


FILE *ptr_file;
    		char c[1000];
FILE *fptr;
   fptr=fopen("decrypted.txt","w+");


    		ptr_file =fopen("to_be_decrypted.txt","r");
    		if (!ptr_file)
        		printf("File not found");

while(fgets(c,1000,ptr_file))
{
dec_fun(a,b,c,fptr);     // decrypt line by line passing n , d , c , pointer to decrypted.txt file
}
FILE *fp;
   fp=fopen("output.txt","w");

stringify(fp,fptr);  // convert the file to readable form   passing pointer to output.txt, decrypted.txt


		fclose(ptr_file); 
		fclose(fptr); 
		fclose(fp); 


}

