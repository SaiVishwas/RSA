void createkey();
void find_phi(mpz_t,mpz_t,mpz_t);
void find_e(mpz_t ,mpz_t  );
void find_phi(mpz_t ,mpz_t,mpz_t );
void find_d(mpz_t ,mpz_t ,mpz_t ,mpz_t );
int enc_fun(char [],char [],char [],FILE *);

void encrypt(char [],char []);
int dec_fun(char [],char [],char [] ,FILE *);

void decrypt(char [],char []);
void generate_prime(mpz_t , mpz_t );
void dec_caller(char [],char []);
    int get_int(char);
void stringify(FILE *,FILE *);
