#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"
int dec_fun(char *a,char *b,char *ch,FILE *fptr)  // n , d , c , pointer to decrypted.txt
{
mpz_t N;
mpz_t c;
mpz_t m;
mpz_t d;
mpz_init(N);
  mpz_set_si(N,0); 
 mpz_init(d);
  mpz_set_si(d,0);
mpz_init(m);
  mpz_set_si(m,0); 
mpz_init(c);
  mpz_set_si(c,0); 
  int flag;

flag = mpz_set_str(N,a, 10); 
  assert (flag == 0); /* If flag is not 0 then the operation failed */
flag = mpz_set_str(d,b, 10); 
  assert (flag == 0);
flag = mpz_set_str(c,ch, 10); 
  assert (flag == 0);

//value of d(decrypted value) is computed here 
mpz_powm (m,c, d, N); // m = (c^d) mod N 

fseek(fptr,0, SEEK_END);  // always go to end and write at the end

  mpz_out_str(fptr,10,m); // to base 10
  fprintf(fptr,"%s","\n");  // write decrypted numbers to decrypted.txt

return 0;

}

