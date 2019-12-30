#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include<stdlib.h>
#include "rsa.h"
void generate_prime(mpz_t p1, mpz_t p2)
{
mpz_t two;
mpz_init(two);
  mpz_set_ui(two,2);
mpz_t one;
mpz_init(one);
  mpz_set_ui(one,1);

int r;
srand(time(NULL));
int s = (rand()%10) + 306;  // (2 ^ 306) gives a 100 digit number, to get random 100+ digit number we add a random number between 0 and 100 to 306; without rand our p1 will always be the same

r = (rand()%10) + 306 + 10 ;  // the extra 10 is make sure there is sufficient gap so that next prime of s != next prime of r

mpz_pow_ui (p1, two,s); // p1 = 2^s
/*
printf ("p1 = ");
  mpz_out_str(stdout,10,p1); // to base 10
  printf ("\n");  */

mpz_pow_ui (p2, two,r); // p2 = 2^r

/*
 printf ("p2 = ");
  mpz_out_str(stdout,10,p2); // to base 10
  printf ("\n"); */

mpz_sub(p1,p1,one);  // p1 = p1 -1 
mpz_sub(p2,p2,one);  // p2 = p2 -1 

mpz_nextprime (p1, p1);
mpz_nextprime (p2, p2);

}
