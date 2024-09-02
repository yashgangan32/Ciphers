#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

unordered_map<char, int> Encrypt={
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
    {' ',10}, {'a',11}, {'b',12}, {'c',13}, {'d',14}, {'e',15}, {'f',16}, {'g',17}, {'h',18}, {'i',19},
    {'j',20}, {'k',21}, {'l',22}, {'m',23}, {'n',24}, {'o',25}, {'p',26}, {'q',27}, {'r',28}, {'s',29},
    {'t',30}, {'u',31}, {'v',32}, {'w',33}, {'x',34}, {'y',35}, {'z',36}
};

void rsa_encrypt(const string& plaintext, mpz_class& ciphertext, const mpz_class& e, const mpz_class& n) {
    mpz_class message;
    for (char c:plaintext) {
        int value=0;
        auto it=Encrypt.find(c);
        if(it!=Encrypt.end()) value=it->second;
        message = message * 100 + value;
        
    }
    mpz_powm(ciphertext.get_mpz_t(), message.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
}

int main() {
    string plaintext = "cryptographyand network security";
    mpz_class p("20200428477062416910393");
    mpz_class q("29850903137512265561199");
    mpz_class n = p * q;
    mpz_class e("65537");
    mpz_class ciphertext;
    rsa_encrypt(plaintext, ciphertext, e, n);
    string ciphertext_str = ciphertext.get_str(36);
    for (char& c : ciphertext_str) {
        c = toupper(c);
    }
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext_str << endl;
    return 0;
}