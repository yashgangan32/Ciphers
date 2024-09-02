#include <iostream>
#include <gmpxx.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void Rprime(mpz_t prime, mpz_t bits) {
    gmp_randstate_t random_state;
    gmp_randinit_default(random_state);
    gmp_randseed_ui(random_state, time(NULL));
    while(1) {
        mpz_urandomb(prime, random_state, mpz_get_ui(bits));
        if(mpz_probab_prime_p(prime, 50)) break;
    }
    gmp_randclear(random_state);
}
void sign_RSA(mpz_t p, mpz_t q,string msg,mpz_t signature) {
    mpz_t n, phi_n, e, temp;
    mpz_init(n);
    mpz_mul(n, p, q);
    mpz_init(phi_n);
    mpz_sub_ui(phi_n, p, 1);
    mpz_t temp2;
    mpz_init_set_ui(temp2,0);
    mpz_sub_ui(temp2, q, 1);
    mpz_mul(phi_n, phi_n, temp2);
    mpz_init(e);
    mpz_init(temp);
    for(mpz_init_set_ui(temp, 2); mpz_cmp(phi_n, temp) > 0; mpz_add_ui(temp, temp, 1)) {
        mpz_gcd(e, temp, phi_n);
        if(mpz_cmp_ui(e, 1) == 0) {
            mpz_set_ui(e,mpz_get_ui(temp));
            break;
        }
    }
    string C = "";
    for(int j = 0; j < msg.length(); j++) {
        int index = -1;
        if(isdigit(msg[j])) index = msg[j] - '0';
        else if(isalpha(msg[j])) index = msg[j] - 'a' + 11; 
        else index = msg[j] - ' ' + 10;
        mpz_t power_res;
        mpz_init(power_res);
        mpz_init_set_ui(power_res, index);
        mpz_powm_ui(power_res, power_res, mpz_get_ui(e), n);
        C += to_string(mpz_get_ui(power_res));
        mpz_clear(power_res);
    }
    mpz_t d;
    mpz_init(d);
    mpz_t k;
    mpz_init(k);
    mpz_invert(d, e, phi_n);
    mpz_powm(signature, signature, d, n);

    cout << "Ciphertext: " << C << endl;
    gmp_printf("%Zd", signature);
}
main(){
    string P="cryptography and network security";
    mpz_t p, q;
    mpz_init(p); mpz_init(q);
    mpz_t bits;
    mpz_init_set_ui(bits, 512);
    Rprime(p, bits); Rprime(q, bits);
    string C="";
    for(int i = 0; i < plain_text.length(); i++) {
        if(isdigit P[i])) C += P[i]-'0'; 
        else if(isalpha P[i])) C += tolower P[i]) - 'a' + 11; 
        else C += P[i] - ' ' + 10;
    }
    mpz_t S;
    mpz_init(S);
    sign_RSA(p, q, C, S);
}