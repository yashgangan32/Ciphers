#include <iostream>
#include <unordered_map>
#include <cctype>
#include <vector>
using namespace std;
#define pb push_back
#define F          first
#define S          second
char key[5][5]={
        {'L', 'A', 'K', 'S', 'H'},
        {'I', 'T', 'U', 'P', 'R'},
        {'E', 'V', 'M', 'N', 'B'},
        {'O', 'W', 'Q', 'X', 'Y'},
        {'Z', 'F', 'C', 'D', 'G'}
    };
void fun(char key[5][5],char ch,int& r,int& c){
    if(ch=='J') ch='I'; 
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(key[i][j]==ch){
                r=i;
                c=j;
            }
        }
    }
}
string PlayFair(char key[5][5],string P,string C){
    if(P.size()%2!=0) P+='X';
    for(int i=0;i<P.size();i+=2){
        int r1,c1,r2,c2;
        fun(key,P[i],r1,c1);
        fun(key,P[i+1],r2,c2);
        if(c1==c2){
            C+=key[(r1+1)%5][c1];
            C+=key[(r2+1)%5][c2];
        }else if(r1==r2){
            C+=key[r1][(c1+1)%5];
            C+=key[r2][(c2+1)%5];
        }else{
            C+=key[r1][c2];
            C+=key[r2][c1];
        }
    }
    return C;
}
main(){
    string P;cin>>P;
    cout<<PlayFair(key,P,"")<<endl;
}