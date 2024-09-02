#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;
#define pb push_back
#define F          first
#define S          second
string RailFence(string P,string C){
    C.pb(P[0]);
    for(int i=1;i<P.size();i+=2) C.pb(P[i]);
    for(int i=2;i<P.size();i+=2) C.pb(P[i]);
    for(char &c:P){
        if(c!=' ' || isdigit(c)) c=toupper(c);
    }
    return C;
}
main(){
    string s;cin>>s;
    cout<<RailFence(s,"")<<endl;
}