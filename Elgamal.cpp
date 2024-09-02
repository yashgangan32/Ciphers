#include <iostream>
#include <gmp.h>
#include <ctime>
using namespace std;

void primitiveRoot(const mpz_t p, mpz_t g) {
    mpz_t q, remainder, exp;
    mpz_inits(q, remainder, exp, NULL);
    mpz_sub_ui(q, p, 1);
    for(mpz_set_ui(g, 2); mpz_cmp(g, p) < 0; mpz_add_ui(g, g, 1)) {
        mpz_powm(exp, g, q, p);
        mpz_mod(remainder, exp, p);
        if(mpz_cmp_ui(remainder, 1) != 0) break;
    }
    mpz_clears(q, remainder, exp, NULL);
}
void generatePrime(mpz_t prime, unsigned int bits) {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));
    mpz_t rand_num;
    mpz_init(rand_num);
    while(1){
        mpz_urandomb(rand_num, state, bits);
        if (mpz_probab_prime_p(rand_num, 50)) {
            mpz_set(prime, rand_num);
            break;
        }
    }
    mpz_clear(rand_num);
    gmp_randclear(state);
}
void Elgamal(const mpz_t p, const mpz_t g, const mpz_t h, const mpz_t plain, mpz_t c1, mpz_t c2) {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));
    mpz_t k;
    mpz_init(k);
    mpz_urandomm(k, state, p);
    mpz_powm(c1, g, k, p);
    mpz_powm(c2, h, k, p);
    mpz_mul(c2, c2, plain);
    mpz_mod(c2, c2, p);
    mpz_clear(k);
    gmp_randclear(state);
}
main() {
    string plain_text="cryptography and network security";
    mpz_t prime, generator, h, private_key, plain_int, c1, c2;
    mpz_inits(prime, generator, h, private_key, plain_int, c1, c2, NULL);
    generatePrime(prime, 512);
    primitiveRoot(prime, generator);
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(NULL));
    mpz_urandomm(private_key, state, prime);
    mpz_powm(h, generator, private_key, prime);
    mpz_set_str(plain_int, plain_text.c_str(), 10);
    Elgamal(prime, generator, h, plain_int, c1, c2);
    gmp_printf("Ciphertext (c1, c2): (%Zd, %Zd)\n", c1, c2);
    mpz_clears(prime, generator, h, private_key, plain_int, c1, c2, NULL);
}