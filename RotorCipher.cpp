#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <vector>
using namespace std;
#define pb push_back
#define F          first
#define S          second
void RotorCipher(vector<int>& k){
    int x=k[0];
    for(int i=0;i<k.size()-1;i++) k[i]=k[i+1];
    k[k.size()-1]=x;
    for(auto& i:k){
        i--;
        if(i==-1) i=36;
    }
}
main(){
    string txt="0123456789 abcdefghijklmnopqrstuvwxyz";
    vector<int> val(256,-1);
    for(int i=0;i<txt.size();i++) val[txt[i]]=i;
    string P;cin>>P;
    string C;
    string key="lakshituprevmnbowqxyzfcdg";
    vector<int> k(37);
    for(int i=0;i<37;i++) k[i]=val[key[i]];
    for(int i=0;i<P.size();i++){
        C.pb(txt[k[val[P[i]]]]);
        RotorCipher(k);
    }
    for(char &c:C){
        if(c!=' ' || isdigit(c)) c=toupper(c);;
    }
    cout<<C<<endl;
}