#include <iostream>
#include <string>
#include <vector>
using namespace std;
void verif();
int main(){
    vector<string> cuv;
    int n;
    int spec;
    string a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        cuv.push_back(a);
    }
    for(auto cuvant:cuv){

    }

}
//f p/u verificarea daca coincide cu un cuvant
void verif(string &a, string &b, int &s){
    int lung=0;
    int incep=0;
    for(int i=0;i<a.length();i++){
        for(int j=incep;j<b.length();j++){
            if(a.at(i)==b.at(j)){
                lung++;
                incep=j+1;
                break;
            }
        }
    }
    if(lung==a.length()){
        s++;
    }
}
