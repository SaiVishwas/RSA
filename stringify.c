#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include<ctype.h>
#include "rsa.h"
#include<string.h>
#include<stdlib.h>
void stringify(FILE *fp,FILE *fptr)  // output.txt , decrypted.txt
{
    		char c[1000];

fseek(fptr, 0, SEEK_SET);
while(fgets(c,1000,fptr))
{
int i=0;
int s;
char ch;

while(i < (strlen(c)-1))  // last character is always nextline '\n' so ignore it
{
s = (get_int(c[i])*100) + (get_int(c[i+1])*10) + (get_int(c[i+2]));  // coverting it to int of 3 digit decimal number
s = s - 100;    // getting back actual ascii value

ch = s ;   // conversion to char

if(s >= 0)
{

fprintf(fp,"%c",ch);    // print it in output.txt

}
i=i+3;
}
}
}
