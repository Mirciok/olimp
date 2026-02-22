#include <iostream>
#include <fstream>
#include <list>
using namespace std;
int main(){
    list<int> sir;
    ofstream fout("linii.out");
    int a, b;
    cin>>a>>b;
    int n=a;
    while(a!=0){
     sir.push_front(a);
     a--;
    }
    if(n/2==b){
        for(int i=0; i<n/2; i++){
            fout<<sir.front()<<" "<<sir.back()<<" "<<sir.front()+sir.back()<<endl;
            sir.pop_front();
            sir.pop_back();
        }
    }else{
    cout<<"NU";
    }
}
