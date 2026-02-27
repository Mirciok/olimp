#include <iostream>
#include <string>
#include <vector>
using namespace std;
void verif(string &a, string &b, int &s);
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
    int total=0;
    for(int i=0; i<cuv.size(); i++){
        for(int j=i+1; j<cuv.size(); j++){
            verif(cuv.at(i), cuv.at(j), total);
        }
    }
    cout<<n-total;

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
