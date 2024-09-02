#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;
#define pb push_back
#define F          first
#define S          second
unordered_map<int,char> Decrypt={
        {0,'0'}, {1,'1'}, {2,'2'}, {3,'3'}, {4,'4'}, {5,'5'}, {6,'6'}, {7,'7'}, {8,'8'}, {9,'9'},
        {10,' '}, {11,'a'}, {12,'b'}, {13,'c'}, {14,'d'}, {15,'e'}, {16,'f'}, {17,'g'}, {18,'h'}, {19,'i'},
        {20,'j'}, {21,'k'}, {22,'l'}, {23,'m'}, {24,'n'}, {25,'o'}, {26,'p'}, {27,'q'}, {28,'r'}, {29,'s'},
        {30,'t'}, {31,'u'}, {32,'v'}, {33,'w'}, {34,'x'}, {35,'y'}, {36,'z'}
    };
unordered_map<char,int> Encrypt={
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
        {' ',10}, {'a',11}, {'b',12}, {'c',13}, {'d',14}, {'e',15}, {'f',16}, {'g',17}, {'h',18}, {'i',19},
        {'j',20}, {'k',21}, {'l',22}, {'m',23}, {'n',24}, {'o',25}, {'p',26}, {'q',27}, {'r',28}, {'s',29},
        {'t',30}, {'u',31}, {'v',32}, {'w',33}, {'x',34}, {'y',35}, {'z',36}
    };
string Ceasar(string P,int k){
    for(int i=0;i<P.size();i++) P[i]=Decrypt[(Encrypt[P[i]]+k)%37];
    for(char &c:P){
        if(c!=' ' || isdigit(c)) c=toupper(c);;
    }
    return P;
}
main(){
    int k;cin>>k;   //Roll No. -> 161 so 1 in my case
    string s;cin>>s;
    string p=Ceasar(s,k);
    cout<<p<<endl;
}