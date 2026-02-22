#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("circuite.in");
ofstream fout("circuite.out");

int numarDeLinii;
string linie;
int a=0;
int card=0;

void parseNOT(string &c, int k){
    if(c[k]=='!'){
        c[k] = (c[k+1] == '1') ? '0' : '1';
        c.erase(k+1, 1);
        card++;
    } else {
    a=1;
    }
}
void parseAND(string &c, int k){
    if(c[k]=='&' && c[k+1]=='&'){
    c[k-1] = ((c[k-1]=='1') && (c[k+2]=='1')) ? '1' : '0';
    c.erase(k, 3);
    card++;
    }else {
    a=1;
    }
}
void parseOR(string &c, int k){
if(c[k]=='|' && c[k+1]=='|'){
    c[k-1] = ((c[k-1]=='1') || (c[k+2]=='1')) ? '1' : '0';
    c.erase(k, 3);
    card++;
    }else {
    a=1;
    }
}
int main(){
    fin>>numarDeLinii;
    for(int l=0; l<numarDeLinii; l++){
        getline(fin, linie);
        while(linie!="0" && linie!="1"){
            for(int i=1; i<linie.length(); i++){
                while(a==0){
                    parseNOT(linie, i); }
                    a=0;
                while(a==0){
                    parseAND(linie, i);}
                    a=0;
                while(a==0){
                    parseOR(linie, i);}
                    a=0;
                    i--;
            }
        }
        fout<<linie<<' ('<<card<<')'<<endl;
    }
}
