#include<iostream>
using namespace std;
int main(){
int tipuri[9]={500, 200, 100, 50, 20, 10, 5, 2, 1};
int bancmon[9];
int banc=0;
int mon;
int s;
cin>>s;
    for(int i=0; i<9; i++){
        bancmon[i]=s/tipuri[i];
        s=s%tipuri[i];
    }
mon=bancmon[7]+bancmon[8];
    for(int i=0; i<7; i++){
        banc=banc+bancmon[i];
    }
    cout<<banc<<" "<<mon<<endl;
    for(int i=0; i<9; i++){
        if(bancmon[i]!=0){
            cout<<tipuri[i]<<" "<<bancmon[i]<<endl;
        }
    }
}
