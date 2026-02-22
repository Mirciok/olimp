#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("domino.in");
    ofstream fout("domino.out");

    int m, n;
    fin >> m >> n;

    // Gradul fiecărui număr (0..m)
    vector<int> grad(m + 1, 0);

    // Construim setul complet de piese domino
    for(int i = 0; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            grad[i]++;
            grad[j]++;
        }
    }

    // Citim piesele eliminate și scădem gradurile lor
    for(int k = 0; k < n; k++) {
        int a, b;
        fin >> a >> b;
        grad[a]--;
        grad[b]--;
    }

    // Numărăm câte numere au grad impar
    int oddCount = 0;
    for(int i = 0; i <= m; i++) {
        if(grad[i] % 2 != 0) oddCount++;
    }

    // Formula Eulerian path pentru numărul minim de trenuri
    int minTrains = max(1, oddCount / 2);

    fout << minTrains;
    return 0;
}
