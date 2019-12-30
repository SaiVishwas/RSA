#include<stdio.h>
#include <assert.h>
#include<gmp.h>
void find_e(mpz_t e,mpz_t phi )  //computes the value of e
{
mpz_t one ;
mpz_init(one);
  mpz_set_si(one,1);
mpz_t two ;
mpz_init(two);
  mpz_set_si(two,2);
mpz_t gcd ;
mpz_init(gcd);
  mpz_set_si(gcd,0);
while(mpz_cmp (e,phi) < 0)   // while e < phi
{
mpz_gcd (gcd,phi,e); // gcd  = gcd(phi , e)
if(mpz_cmp (one,gcd) == 0) // one == gcd
{
	break;
}
else
{
 mpz_add (e,e,two); // e = e + two
}
}

}
