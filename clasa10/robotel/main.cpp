#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void distanta(int n, int m, int noptim, int moptim, vector<vector<int>> &sala);
int main(){
    int n, m, td, ts, tm, noptim, moptim;
    long long timp;
    cin>>n>>m>>td>>ts>>tm;
    timp=0;
    vector<vector<int>> sala(n, vector<int>(m));
    noptim=n/2+1;
    moptim=m/2+1;
    cout<<noptim<<" "<<moptim<<endl;
    distanta(n, m, noptim, moptim, sala);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                timp=timp+sala[i][j]*td;
            }
        }
    timp=timp*2+n*m*(ts+tm);
    cout<<timp;
}
void distanta(int n, int m, int noptim, int moptim, vector<vector<int>> &sala){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sala[i][j]=max(abs(i-(noptim-1)), abs(j-(moptim-1)));
        }
    }
}
