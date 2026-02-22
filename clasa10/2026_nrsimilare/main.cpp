#include <iostream>
using namespace std;
int reducere(int &numar);
int main(){
int x, n, y;
cin>>x>>n;
int nr[n];
    for(int i=0; i<n; i++){
        cin>>y;
        nr[i]=y;
    }
    y=reducere(x);
    x=0;
    for(int num:nr){
        if(reducere(num)==y){
            x++;
        }
    }
    cout<<x;
}


//functie pentru a aduna cifrele intre ele
int reducere(int &numar){
    while(true){
        int n=0;
        while(numar!=0){
            n=numar%10+n;
            numar/=10;
        }
        numar=n;
        if(numar/10==0){
            break;
        }else{
            n=0;
            continue;
        }
    }
    return numar;
}
