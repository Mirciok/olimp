#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int a=0; a<=7; a++){
        for(int b=a+1; b<=8; b++){
            for(int c=b+1; c<=9; c++){
                if(a+b+c==n){
                    cout<<a<<b<<c<<endl;
                }
            }
        }
    }
}
