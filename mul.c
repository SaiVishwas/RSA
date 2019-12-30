#include<stdio.h>
#include<gmp.h>
#include <assert.h>
#include <limits.h>
#include<stdlib.h>
void addit(mpz_t,mpz_t ,mpz_t );
int main()
{

char inputStr[1025];
  /* 
     mpz_t is the type defined for GMP integers. 
     It is a pointer to the internals of the GMP integer data structure 
   */
  mpz_t n; 
  mpz_t m; 
  mpz_t p; 
  int flag;
 
  printf ("Enter your number: ");
  scanf("%1024s" , inputStr); /* NOTE: never ever write a "raw" call to 
                                 scanf ("%s", inputStr);  
                                 You are potentially leaving a 
                                 security hole in your code.
 
                                 Also, inputStr is set to 1025 bytes to allow 
                                 scanf to write '\0' at the end. :-)     
                                 Thanks to Peter Schmidt-Nielsen for the fix.
                               */
 
  /* 1. Initialize the number */
  mpz_init(n);
  mpz_set_si(n,0); 
 mpz_init(m);
  mpz_set_si(m,3); 

  /* 2. Parse the input string as a base 10 number */
  flag = mpz_set_str(n,inputStr, 10); 
  assert (flag == 0); /* If flag is not 0 then the operation failed */
 
  /* Print n */
  printf ("n = ");
  mpz_out_str(stdout,10,n); // to base 10
  printf ("\n");

/* 5. Square n */
 
  mpz_mul(n,n,n); /* n = n * n */
 
 
  printf (" (n )^2 = ");
  mpz_out_str(stdout,10,n);
  printf ("\n");

  mpz_powm (m,n,n,m);
printf ("(n^n)mod(m) = ");
  mpz_out_str(stdout,10,m); // to base 10
  printf ("\n");

 mpz_gcd (m,n,m);
printf ("gcd = ");
  mpz_out_str(stdout,10,m); // to base 10
  printf ("\n");
mpz_t one;
mpz_init(one);
  mpz_set_ui(one,1);

mpz_sub (m,m,one);
printf ("difference = ");
  mpz_out_str(stdout,10,m); // to base 10
  printf ("\n");
 //Determine whether n is prime. Return 2 if n is definitely prime, return 1 if n is probably prime (without being certain), or return 0 if n is definitely composite. 
int q;
printf("Enter no. to be checked if prime");
scanf("%d",&q);
mpz_init(p);
  mpz_set_ui(p,q);
 int ch =9;
ch = mpz_probab_prime_p (p, 25);
printf("prime : %d",ch);
printf ("m = ");
  mpz_out_str(stdout,10,m); // to base 10
  printf ("\n");
printf ("n = ");
  mpz_out_str(stdout,10,n); // to base 10
  printf ("\n");
addit(m,m,n);
printf ("sum = ");
  mpz_out_str(stdout,10,m); // to base 10
  printf ("\n");
printf("float");
 mpf_t x,y;
       mpf_init (x);   
 mpf_set_si (x, 3.1325151);
gmp_printf("%.100Fx\n",x);    
mpf_init (y);   
 mpf_set_si (y, 0);
printf ("x = ");
  mpf_out_str(stdout,10,0,x); // to base 10
  printf ("\n");
mpf_floor (y, x);
printf ("y = ");
  mpf_out_str(stdout,10,0,y); // to base 10
  printf ("\n");
gmp_printf("%.100Fx\n",x);    
printf("%d",mpf_cmp(x,y));
mpz_t two;
mpz_init(two);
  mpz_set_ui(two,2);
mpz_t pow;
mpz_init(pow);
  mpz_set_ui(pow,1);
mpz_pow_ui (pow, two,339);
printf ("pow = ");
  mpz_out_str(stdout,10,pow); // to base 10
  printf ("\n");
mpz_t nxt_prime;
mpz_init(nxt_prime);
  mpz_set_ui(nxt_prime,1);
mpz_nextprime (nxt_prime, pow);
printf ("next prime = ");
  mpz_out_str(stdout,10,nxt_prime); // to base 10
  printf ("\n");
int r;
r = rand();
printf("r = %d",r);
srand(time(NULL));
int s = (rand()%100) + 300;;
printf("s = %d",s);
r = (rand()%100) + 369;
printf("r = %d",r);
  /* 6. Clean up the mpz_t handles or else we will leak memory */
  mpz_clear(n);
return 0;
}

void addit(mpz_t s,mpz_t m,mpz_t n)
{
mpz_add (s,m,n);

}
