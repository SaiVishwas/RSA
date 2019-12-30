#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"
#include<string.h>
#include<stdlib.h>
void dec_caller(char *a,char *b)
{
FILE *ptr_file;
    		char c[1000];
ptr_file =fopen("str_to_int.txt","r");
    		if (!ptr_file)
        		printf("File not found");
while(fgets(c,1000,ptr_file))
{
//printf("%s",c);
dec_fun(a,b,c);
}
		fclose(ptr_file); 
}
