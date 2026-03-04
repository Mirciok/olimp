#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, a;
    int total=0;
    int serunu=0;
    cin>>n;
    int servere[n];
    for(int i=0; i<n; i++){
        cin>>a;
        total=total+a;
        servere[i]=a;
    }
    sort(servere, servere+n);
    total=total/2;
    for(int i=0; i<n; i++){
        if(serunu+servere[i]<total){
            serunu=serunu+servere[i];
        }else{
            break;
        }
    }
    total=0;
    for(int i=0; i<n; i++){
        total=total+servere[i];
    }
    total=total-serunu;
    cout<<serunu<<" "<<total;
}
