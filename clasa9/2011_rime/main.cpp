#include <iostream>
#include <fstream>
using namespace std;
int main(){
ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");

string cuvant;
string rima;
string aux=" ";
int p;
int k;
int h=0;
fin>>cuvant;
p=cuvant.length();
while(fin>>rima){

    k=rima.length();
    if(k>=3){
    if(rima[k-1]==cuvant[p-1]&&rima[k-2]==cuvant[p-2]&&rima[k-3]==cuvant[p-3]){
        fout<<rima<<" ";
        h++;
    }else{

    continue;
    }
    }
}
if(h==0){
    cout<<"NU";
}
}
