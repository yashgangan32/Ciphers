#include <iostream>
#include <unordered_map>
#include <cctype>
#include <vector>
using namespace std;
#define pb push_back
#define F          first
#define S          second
string Vigenere(string s,string key) {
    string C;
    for(int i=0;i<s.size();i++){
        char x=(s[i]+key[i])%26;
        x+='A';
        C.push_back(x);
    }
    return C;
}
string fun(string s,string key){
    int sLen=s.size();
    int kLen=key.size();
    if(kLen<sLen){
        for(int i=0;i<sLen-kLen;i++) key+=key[i%kLen];
    }
    else if(kLen>sLen) key=key.substr(0,sLen);
    return key;
}
main(){
    string s;cin>>s;
    string K_trad="lakshituprevmnbowqxyzfcdg";
    string k=fun(s,K_trad);
    cout<<Vigenere(s,k)<<endl;
}