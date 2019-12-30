#include<stdio.h>
#include <assert.h>
#include<gmp.h>
void find_d(mpz_t d,mpz_t k,mpz_t e,mpz_t phi)  //computes the value of d
{
mpz_t one ;
mpz_init(one);
  mpz_set_si(one,1);




mpz_mul(d,k,phi);  // d = k * phi
mpz_add(d,d,one); // d = d + 1
mpz_div (d,d, e);  // d = d / e



}
