#include <iostream>
using namespace std;
int main(){
    int n;
    int tot=1;
    int zerouri=0;
    cin>>n;
    for(int i=2; i<=n; i++){
        tot=tot*i;
    }
    while(true){
        if(tot%10==0){
            zerouri++;
            tot=tot/10;
        }else{
        tot=tot/10;
        }
        if(tot==0) break;
    }
    cout<<zerouri;
}
