#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

struct abonatii{
    string abonat;
    int consum;
};

int main() {
    ifstream fin("energie.in");
    ofstream fout("energie.out");

    string numele, prenumele;
    float suma = 0;
    int total, consumul;

    fin >> total;

    vector<abonatii> numarul;

    for (int i = 0; i < total; i++) {
        fin >> numele >> prenumele >> consumul;
        numarul.push_back({numele + prenumele, consumul});
    }

    
    for (auto &i : numarul) {
        suma += i.consum;
    }

    suma /= total;

    
    suma = floor(suma * 100) / 100;

    
    sort(numarul.begin(), numarul.end(), [](const abonatii &a, const abonatii &b) {
        return a.consum < b.consum;
    });

    fout<<"          "<<suma<<endl;
    for (auto &num : numarul) {
        fout << num.abonat << " " << num.consum << endl;
    }



    return 0;
}
