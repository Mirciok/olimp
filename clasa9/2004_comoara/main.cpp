#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> x;
    vector<int> y;

    int a,b;

    for(int i=0; i<3; i++){
        cin>>a;
        cin>>b;
        x.push_back(a);
        y.push_back(b);
    }
    if(x.at(0)==x.at(1)){
        x.at(0)=x.at(2);
        x.at(1)=x.at(2);
    }
    if(x.at(0)==x.at(2)){
        x.at(0)=x.at(1);
        x.at(2)=x.at(1);
    }
    if(x.at(1)==x.at(2)){
        x.at(2)=x.at(0);
        x.at(1)=x.at(0);
    }
    cout<<x.at(0)<<" ";
    if(y.at(0)==y.at(1)){
        y.at(0)=y.at(2);
        y.at(1)=y.at(2);
    }
    if(y.at(0)==y.at(2)){
        y.at(0)=y.at(1);
        y.at(2)=y.at(1);
    }
    if(y.at(1)==y.at(2)){
        y.at(2)=y.at(0);
        y.at(1)=y.at(0);
    }
    cout<<y.at(0);
}
