#include <iostream>
using namespace std;

long long fact(int x) {
    long long r = 1;
    for(int i = 1; i <= x; i++)
        r *= i;
    return r;
}

int main() {
    int n;
    cin >> n;

    long long Cn = fact(2*n) / (fact(n+1) * fact(n));
    cout << Cn;
}
