#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n;
    ifstream fin("muntele.in");
    ofstream fout("muntele.out");
    fin>>n;
    long long a=1,b=1,c;

    for(int i=1; i<n; i++){
        c=a+b;
        a=b;
        b=c;
    }
    fout<<c;
}
