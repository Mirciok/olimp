#include <iostream>
//#include <fstream>
#include <vector>
#include <set>
#include <cctype>
#include <string>
using namespace std;
int main(){
    //ifstream fin("cuvintele.in");
    //ofstream fout("cuvintele.out");
    vector<string> cuvinte;
    string cuvant;
    int numar;
    int maximum=0;
    cin>>numar;
    string rezultat=" ";
    bool mic=false;
    bool mare=false;

    for(int i=0; i<numar; i++){
            //fin>>cuvant;
            cin>>cuvant;
            cuvinte.push_back(cuvant);
    }

    for(int i=cuvinte.size()-1; i>=0; i--){
        for(int j=0; j<cuvinte.at(i).size(); j++){
            if(isupper(cuvinte.at(i).at(j))){
                mare=true;
            } else if(islower(cuvinte.at(i).at(j))){
                mic=true;
            }
    }
    if(!mic||!mare){
        cuvinte.erase(cuvinte.begin()+i);
    }
    mic=false;
    mare=false;
    }
    for(int i=cuvinte.size()-1; i>=0; i--){
        if(cuvinte.at(i).size()>maximum){
            maximum=cuvinte.at(i).size();
            rezultat=cuvinte.at(i);
  } } //fout<<cuvinte.at(0);
   cout<<rezultat;

}
