#include <iostream>
using namespace std;
int main(){
    int n, m, q, x;
    cin>>n>>m;
    int aeroport[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>q;
            aeroport[i][j]=q;
        }
    }
    cout<<endl;
    q=0;
    x=0;
    for(int i=0; i<n; i++){
        q=q+aeroport[i][0];
    }
    for(int i=0; i<m; i++){
        q=q+aeroport[n-1][i];
    }
    for(int i=0; i<m; i++){
        x=x+aeroport[0][i];
    }
    for(int i=0; i<m; i++){
        x=x+aeroport[i][m-1];
    }
    if(q<x) cout<<q<<"JOS DREAPTA";
        else cout<<x<<"DREAPTA JOS";
}
