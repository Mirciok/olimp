//Eng: THIS CODE IS NOT ACCURATE, IT DOESN'T ASSURE A 100% ACCURACY
//Ro: ACEST COD NU ESTE CORECT, NU ÎȚI ASIGURĂ O ACURATEȚE DE 100%

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool stergePiese(vector<int> piesa1, vector<int> piesa2) {
	if((piesa1[0]==piesa2[0]&&piesa1[1]==piesa2[1])||(piesa1[1]==piesa2[0]&&piesa1[0]==piesa2[1])) {
		return true;
	} else {
		return false;
	}
}
bool punePiese(vector<int>& piesa1, vector<int>& piesa2) {
	if(piesa1[0]==piesa2[0]) {
		piesa2[0]=piesa1[1];
		return true;
	} else if(piesa1[0]==piesa2[1]) {
		piesa2[1]=piesa1[1];
		return true;
	} else if(piesa1[1]==piesa2[0]) {
		piesa2[0]=piesa1[0];
		return true;
	} else if(piesa1[1]==piesa2[1]) {
		piesa2[1]=piesa1[0];
		return true;
	} else {
		return false;
	}
}

int main() {
	ifstream fin("domino.in");
	ofstream fout("domino.out");
	int m, n;
	int aux=0;
	fin>>m>>n;
	vector<vector<int>> piesePrezente;
	vector<vector<int>> pieseAbsente;
	vector<vector<int>> trenuri;

	for(int i=0; i<n; i++) {

		int a, b;
		fin>>a>>b;
		pieseAbsente.push_back({a,b});

	}

	for(int i=0; i<=m; i++) {
		for(int j=0; j<=m; j++) {
			if(i<=j) {
				piesePrezente.push_back({i,j});
			}
		}
	}

	for(int i=0; i<piesePrezente.size(); i++) {
		for(int j=0; j<pieseAbsente.size(); j++) {
			if(stergePiese(pieseAbsente[j], piesePrezente[i])) {
				piesePrezente.erase(piesePrezente.begin()+i);
				i--;
				break;
			}
		}
	}

	if(piesePrezente.empty()) {
		fout << 0;
		return 0;
	}

	trenuri.push_back(piesePrezente[0]);
	piesePrezente.erase(piesePrezente.begin());

	for(int j=0; j<trenuri.size(); j++) {
    for(int i=0; i<piesePrezente.size(); ) { 
        if(punePiese(piesePrezente[i], trenuri[j])) {
            piesePrezente.erase(piesePrezente.begin() + i); 
        } else {
            trenuri.push_back(piesePrezente[i]); 
            piesePrezente.erase(piesePrezente.begin() + i); 
        }
    }
}


bool trainsMerged = true;

while(trainsMerged) {
    trainsMerged = false;
    
    for(int i = 0; i < trenuri.size(); i++) {
        for(int j = i + 1; j < trenuri.size(); j++) {
            int a1 = trenuri[i][0], b1 = trenuri[i][1];
            int a2 = trenuri[j][0], b2 = trenuri[j][1];
            vector<int> merged;

          
            if(b1 == a2) merged = {a1, b2};
            else if(b1 == b2) merged = {a1, a2};
            else if(a1 == a2) merged = {b1, b2};
            else if(a1 == b2) merged = {b1, a2};
            else continue;

            
            trenuri.erase(trenuri.begin() + j); 
            trenuri.erase(trenuri.begin() + i);
            trenuri.push_back(merged);          
            trainsMerged = true;

            i = -1; 
            break; 
        }
    }
}


	fout<<trenuri.size();
}
