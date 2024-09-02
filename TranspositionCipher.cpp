#include <iostream>
#include <unordered_map>
#include <cctype>
#include <vector>
using namespace std;
#define pb push_back
#define F          first
#define S          second
string Transposition(string P) {
    int n=P.size()/5 + 1;
    vector<vector<char>> v(n,vector<char>(5,'L'));
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(j!=P.size()-1) v[i][j]=P[(5*i)+j];
        }
    }
    for(int j=0;j<5;j++) {
        for(int i=0;i<n;i++) P[i+(5*j)]=v[i][j];
    }
    for(char &c:P){
        if(c!=' ' || isdigit(c)) c=toupper(c);;
    }
    return P;
}
main(){
    string s;cin>>s;
    cout<<Transposition(s)<<endl;
}