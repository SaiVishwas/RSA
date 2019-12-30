#include<stdio.h>
#include <assert.h>
#include<gmp.h>
#include "rsa.h"
int enc_fun(char *a,char *b,char *ch,FILE *fptr)
{
mpz_t N;
mpz_t c;
mpz_t m;
mpz_t e;

mpz_init(N);
  mpz_set_si(N,0); 
 mpz_init(e);
  mpz_set_si(e,0); 
mpz_init(m);
  mpz_set_si(m,0);
mpz_init(c);
  mpz_set_si(c,0);
  int flag;

flag = mpz_set_str(N,a, 10); // n gets contents of a
  assert (flag == 0); /* If flag is not 0 then the operation failed */
flag = mpz_set_str(e,b, 10); 
  assert (flag == 0);
flag = mpz_set_str(m,ch, 10); 
  assert (flag == 0);

//value of c(encrypted value) is computed here
mpz_powm (c,m, e, N);   // c = (m ^ e) mod N 

fseek(fptr,0, SEEK_END);

  mpz_out_str(fptr,10,c); // to base 10
  fprintf(fptr,"%s","\n");   // write encrypted text into encypted.txt


return 0;

}

