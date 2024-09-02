#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
#define pb push_back
#define F          first
#define S          second
int M=37;
char txt[37];
unordered_map<char,int> m;
main(){
    for(int i=0;i<10;i++) txt[i]='0'+i,m['0'+i]=i;
    txt[10]=' ',m[' ']=10;
    for(int i=11;i<M;i++) txt[i]='a'+i-11,m['a'+i-11]=i;
    string P;cin>>P;
    string k="lakshituprevmnbowqxyzfcdg 0123456789";
    vector<int> trad(M);
    for(int i=0;i<M;i++) trad[i]=m[k[i]];
    if(P.size()%M!=0) P+=string(M-P.size()%M,'x');
    string C(P.size(),'X');
    for(int i=0;i<P.size()/37;i+=M){
        for(int j=0;j<M;j++) C[i+trad[j]]=P[i+j];
    }
    for(char &c:C){
        if(c!=' ' || isdigit(c)) c=toupper(c);;
    }
    cout<<C<<endl;
}