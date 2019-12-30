#include<stdio.h>
#include <assert.h>
#include <gmp.h>
#include<stdlib.h>
#include "rsa.h"


int
miller_rabin(mpz_t n, int k)
{
  int res;
  mpz_t f[MAX_DECOMPOSE];
  mpz_t s, d, a, x, r;
  mpz_t n_1, n_3;
  gmp_randstate_t rs;
  int l = 0;

  res = 0;  // false
  gmp_randinit_default (rs);


  mpz_init (d);
  mpz_init (a);
  mpz_init (x);
  mpz_init (r);
  mpz_init (n_1);
  mpz_init (n_3);
  mpz_t one;
  mpz_init (one);
  mpz_set_ui (one, 1);
  mpz_t two;
  mpz_init (two);
  mpz_set_ui (two, 2);
  mpz_t three;
  mpz_init (three);
  mpz_set_ui (three, 3);
  mpz_init (s);
  mpz_set_ui (s, 0);		// s=0
  mpz_init (d);



  mpz_sub (n_1, n, one);	// n_1 stands for n-1
  mpz_set (d, n_1);		// d = n - 1
  mpz_sub (n_3, n, three);	// n_3 stands for n-3

// to represent n − 1 as (2^s)*d
  while (mpz_even_p (d) != 0)	// while n_1 is even
    {
      mpz_add (s, s, one);      // s=s+1
      mpz_cdiv_r (d, d, two);	// d=d/2
    }

  int i = 0;
  while (i < k)
    {
      mpz_urandomm (a, rs, n_3);	// picking a random integer between 0 to n-4
      mpz_add_ui (a, a, 2);	// adding two to it get the random integer between 2 to n-2 that we need
      mpz_powm (x, a, d, n);	// x = a^d mod n
      if ((mpz_cmp_ui (x, 1) == 0) || (mpz_cmp (x, n_1) == 0))	// x = 1 or x = n-1
	continue;                  // could be prime

      while (mpz_cmp (r, s) < 0)	//  while r < s
	{
	  mpz_powm_ui (x, x, 2, n);  
	  if (mpz_cmp (x, one) == 0)
	    return 0;      		// definitely composite
	  if (mpz_cmp (x, n_1) == 0)
	    continue;			// may be prime

	}

      return 0;  // definitely composite

    }

  return 1;  // probably prime

}
