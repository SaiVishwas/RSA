#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"
#include<string.h>
#include<stdlib.h>
void enc_caller(char *a,char *b)  // n, a
{
FILE *ptr_file;
    		char c[1000];
ptr_file =fopen("str_to_int.txt","r");
    		if (!ptr_file)
        		printf("File not found");
FILE *fptr;
   fptr=fopen("encrypted.txt","w");
while(fgets(c,1000,ptr_file))
{

enc_fun(a,b,c,fptr);  //calls the function to encrypt; passing n , e , m , pointer to encrypted.txt file (output) as arguments
}
		fclose(ptr_file); 
		fclose(fptr); 
}
