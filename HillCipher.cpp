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
void fun(int cMat[][1],char key[][5],int msgVec[][1]){
    for(int i=0;i<5;i++){
        for(int j=0;j<1;j++){
            cMat[i][j]=0;
            for(int x=0;x<5;x++) cMat[i][j]+=key[i][x]*msgVec[x][j];
            cMat[i][j]%=26;
        }
    }
}
string HillCipher(string P){
    while(P.size()%5!=0) P+='X';
    string C="";
    vector<string> v;
    for(int i=0;i<P.size();i+=5) v.push_back(P.substr(i,5));
    for(const auto& sub:v){
        int msgVec[5][1];
        for(int i=0;i<5;i++) msgVec[i][0]=sub[i]-'A';
        int cMat[5][1];
        fun(cMat,key,msgVec);
        for(int i=0;i<5;i++) C+=cMat[i][0]+'A';
    }
    return C;
}
main(){
    string s;cin>>s;
    cout<<HillCipher(s)<<endl;
}