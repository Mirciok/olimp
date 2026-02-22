#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            for(int k=0; k<cuv.at(i).size(); k++){
                for(int l=0; l<cuv.at(j).size(); l++){
                  if(cuv.at(i).at(k)==cuv.at(j).at(l)){
                      cuv.erase(cuv.begin())
                  }
                }
            }
        }
    }
    return 0;
}
