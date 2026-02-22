#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin("anagrame.in");
    ofstream fout("anagrame.out");

    int n;
    string s;
    fin>>n;
    vector<string> cuvinte;

    while(fin>>s){
       cuvinte.push_back(s);
    }
    for(int i=0; i<n; i++){
        sort(cuvinte[i].begin(), cuvinte[i].end());
    }
    sort(cuvinte.begin(), cuvinte.end());
    int distinct =0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || cuvinte[i] != cuvinte[i - 1]) {
            distinct++;
        }
    }
    fout<<distinct;
}
