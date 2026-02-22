#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int x, n, z=0;

    ifstream fin("cadou.in");
    ofstream fout("cadou.out");

    fin>>x>>n;
    int y=x;

    for(int i=1; i<=n; i++){
        x=x*2+i;
    }
    fout<<x<<endl;

    while(y<1000){
        y=y*2+1;
        z++;
    }
    if(z<=n){
        fout<<z;
    } else {
    fout<<0;
    }
}
