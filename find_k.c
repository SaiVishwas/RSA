#include<stdio.h>
#include <assert.h>
#include<gmp.h>
void find_k(mpz_t k,mpz_t e,mpz_t phi)  //computes the value of k
{
mpz_t one ;
mpz_init(one);
  mpz_set_si(one,1);
mpz_t zero ;
mpz_init(zero);
  mpz_set_si(zero,0);
mpz_t tmp ;
mpz_init(tmp);
  mpz_set_si(tmp,0);
mpz_t rem ; // remainder
mpz_init(rem);
  mpz_set_si(rem,-1);

while(1)
{
mpz_mul(tmp,k,phi);  // tmp = k * phi
mpz_add(tmp,tmp,one);  // tmp = tmp + 1
mpz_mod (rem,tmp, e);  // rem = tmp mod e
if(mpz_cmp(rem,zero) == 0)  // if rem == zero
	break;
else
	mpz_add(k,k,one);   // k = k + 1
}


}
