#include<stdio.h>
#include<gmp.h>
#include "rsa.h"
#include <sys/time.h>
//this is the client code
int main()
{
	struct timeval t1;
	struct timeval t2;
	int c;
	do
	{
		printf("\n\n Enter 1. to Create the keys(public and private),  2. to Encrypt , 3. to Decrypt and 4. to Exit \n");
		scanf("%d",&c);

		switch(c)
		{
			case 1: 
				
				gettimeofday(&t1, NULL);
				createkey();                   // calling the function to create the public and private keys
				gettimeofday(&t2, NULL);
				printf("\n %ld seconds ",t2.tv_sec - t1.tv_sec);
				printf("\t %ld micro seconds",t2.tv_usec - t1.tv_usec); //computing the time required to create the keys
				break;
	
			case 2:
				printf("Enter N");
				char N1[1025];
				scanf("%1024s",N1);
				printf("Enter public(encryption) key");
				char e[1025];
				scanf("%1024s",e);
				
				gettimeofday(&t1, NULL);
				encrypt(N1,e);          // calling the function to encrypt contents of the input.txt file
				gettimeofday(&t2, NULL);
				printf("\n %ld seconds ",t2.tv_sec - t1.tv_sec);
				printf("\t %ld micro seconds",t2.tv_usec - t1.tv_usec); //computing the time required to encrypt

				break;

			case 3:
				printf("Enter N");
				char N2[1025];
				scanf("%1024s",N2);
				printf("Enter private(decryption) key");
				char d[1025];
				scanf("%1024s",d);
				
				gettimeofday(&t1, NULL);
				decrypt(N2,d);       // calling the function to decrypt the contents of the to_be_decrypted.txt file
				gettimeofday(&t2, NULL);
				printf("\n %ld seconds ",t2.tv_sec - t1.tv_sec);
				printf("\t %ld micro seconds",t2.tv_usec - t1.tv_usec); //computing the time required to decrypt
				break;
	
			case 4:
				break;	
		
			default:
				printf("Wrong choice !!!");
		}
	}while(c != 4);

	return 0;
}

