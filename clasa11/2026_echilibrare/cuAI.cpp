#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    int total = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    
    // dp[j] = true daca putem forma suma j cu un subset
    vector<bool> dp(total + 1, false);
    dp[0] = true;
    
    for(int i = 0; i < n; i++){
        // parcurgem de la total spre 0 pentru a nu refolosi acelasi element
        for(int j = total; j >= a[i]; j--){
            if(dp[j - a[i]]){
                dp[j] = true;
            }
        }
    }
    
    // gasim cea mai apropiata suma de total/2
    int server1 = 0;
    for(int j = total / 2; j >= 0; j--){
        if(dp[j]){
            server1 = j;
            break;
        }
    }
    
    int server2 = total - server1;
    cout << server1 << " " << server2;
    
    return 0;
}
