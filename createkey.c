#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"


void createkey()
{

  int flag;
	mpz_t p1; //declaration for prime number 1
  mpz_t p2;   //declaration for prime number 2
mpz_t one;
mpz_init(one);
  mpz_set_si(one,1);

  mpz_init(p1);
  mpz_set_si(p1,0); // initializing p1 to 0
 mpz_init(p2);
  mpz_set_si(p2,0);  // initializing p2 to 0

generate_prime(p1,p2);  //  calling the function to generate the prime numbers
  printf ("p1 = ");
  mpz_out_str(stdout,10,p1); // to base 10
  printf ("\n");

  printf ("\np2 = ");
  mpz_out_str(stdout,10,p2); // to base 10
  printf ("\n");

if((mpz_probab_prime_p (p1, 25)==0) || (mpz_probab_prime_p (p2, 25)==0))  // check for primality once before printing just to be sure
	printf("The numbers you entered might not be prime \n");


else
{
mpz_t N;
mpz_init(N);
  mpz_set_ui(N,0);
mpz_mul(N,p1,p2); // n = p1 * p2
printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- \n");
printf ("N : \n");
  mpz_out_str(stdout,10,N); // to base 10
  printf ("\n");
printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- \n");
mpz_t phi;
mpz_init(phi);
  mpz_set_si(phi,0); 
find_phi(phi,p1,p2);  // call function to evaluate phi(N) = (p1-1)*(p2-1)
printf ("phi : \n ");
  mpz_out_str(stdout,10,phi); // to base 10
  printf ("\n");
mpz_t e;
mpz_init(e);
  mpz_set_si(e,65537);  // initialise e to 65537 
find_e(e,phi); // call the function to compute e such that gcd(e,phi) = 1
printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- \n");
printf ("Public (Encryption) Key :\n ");
  mpz_out_str(stdout,10,e); // to base 10
  printf ("\n");
mpz_t k;
mpz_init(k); 
  mpz_set_si(k,0);
find_k(k,e,phi); // call the function to compute k such that (k*phi + 1) % e == 0
/*printf ("K = ");
  mpz_out_str(stdout,10,k); // to base 10
  printf ("\n");*/

mpz_t d;
mpz_init(d);
  mpz_set_si(d,0);
find_d(d,k,e,phi); // call the function to compute d such that d = (k*phi + 1) / e
printf ("\nPrivate (Decryption) Key : \n ");
  mpz_out_str(stdout,10,d); // display the contents,to base 10 
//  printf ("\n");
printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- \n");
}


}
