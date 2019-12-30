#include<stdio.h>
#include <assert.h>
#include<gmp.h>
void find_phi(mpz_t phi,mpz_t p1,mpz_t p2 )  //computes the value of phi
{
mpz_t one ;
mpz_init(one);
  mpz_set_si(one,1);

mpz_sub (p1,p1,one);   // p1 = p1 - 1
mpz_sub (p2,p2,one);  // p2 = p2 - 1
mpz_mul(phi,p1,p2);   // phi = p1 * p2

}
