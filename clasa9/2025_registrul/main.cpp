#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //ifstream fin("registrul.in");
    //ofstream fout("registrul.out");

    int n;
    int cl;
    int start=0;
    int ord;
    double med;
    //fin>>n;
    cin>>n;

    struct Elev{
        int clasa;
        int ordine;
        double medie;
    };


    vector<Elev> pers;

    for(int i=0; i<n; i++){
        //fin>>cl>>ord>>med;
        cin>>cl>>ord>>med;
        pers.push_back({cl, ord, med});
    }
    for(int i=pers.size()-1; i>=0; i--){
        if(pers.at(i).medie<9){
            pers.erase(pers.begin()+i);
        }
    }
    for(int i = 0; i < pers.size() - 1; i++){
        for(int j = 0; j < pers.size() - i - 1; j++){
            if(pers[j].clasa > pers[j+1].clasa){
                swap(pers[j], pers[j+1]);
            }
        }
    }
    while(start<pers.size()){
        int end=start;
        while(end<pers.size()&&pers[end].clasa==pers[start].clasa){
            end++;
        }
        for(int i = start; i<end; i++){
            for(int j = start; j<end-1; j++){
                if(pers[j].ordine > pers[j+1].ordine){
                    swap(pers[j], pers[j+1]);
                }
            }
        }
        start=end;
    }
    start=0;
    while(start<pers.size()){
        int end=start;
        while(end<pers.size()&&pers[end].clasa==pers[start].clasa){
            end++;
        }
        //fout<<pers[end-1].clasa<<endl;
        cout<<pers[end-1].clasa<<endl;
        for(int i=start; i<end; i++){
            //fout<<pers[i].ordine<<" ";
            cout<<pers[i].ordine<<" ";
        }
        //fout<<endl;
        cout<<endl;
        start=end;
    }
}
