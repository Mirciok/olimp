#include <iostream>
#include <set>
#include <fstream>
using namespace std;
int main(){
ifstream fin("cifre.in.txt");
ofstream fout("cifre.out");
set<char> a;
string k="NU";
string n;
fin>>n;
for(char c:n){
    a.insert(c);
}
for(char m:a){
    fout<<m;
}
fout<<endl;
for(char i:a){
        if(i%2==0){
            k=i;

            break;
        }
    }
    fout<<k;
}
