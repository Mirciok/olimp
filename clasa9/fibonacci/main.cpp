#include <iostream>

using namespace std;

int main()
{
    int n;
    int tot=0;
    int un=1;
    int doi=1;
    cin>>n;
    for(int i=0; i<=n; i++){
        doi=un+doi;
        un=doi-un;
        tot=tot+doi;
    }
    cout<<tot;
}
