#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int k = 3; k*k <= n; k += 2){
        if(n % k == 0)
            return false;
    }
    return true;
}

int main(){
    int a, b, c = 0;
    cin >> a >> b;

    for(int i = a; i <= b; i++){
        if(!isPrime(i)) continue;

        for(int j = i+2; j <= b; j++){
            if(!isPrime(j)) continue;
            if(abs(i-j) == 2){
                cout << i << " " << j << endl;
                c++;
            }
        }
    }

    if(c == 0){
        cout << "nu exista";
    }
}
