#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int main(){
    int numar, a=0, b=0, c=0;
    stack<char> simbolurile;
    string expresia;

    ifstream fin("expresii.in");
    ofstream fout("expresii.out");

    fin>>numar;

    while(fin>>expresia){
            bool nu=true;
        for(int i=0; i<expresia.length(); i++){
            if(expresia[i]=='{' || expresia[i]=='[' || expresia[i]=='('){
            simbolurile.push(expresia[i]);
            } else if (expresia[i]==')'){
                if(!simbolurile.empty() && simbolurile.top()=='('){
                    simbolurile.pop();
                    a++;
                   } else {
                   nu=false;
                   }


            }else if (expresia[i]==']'){
                if(!simbolurile.empty() && simbolurile.top()=='['){
                    simbolurile.pop();
                    b++;
                } else {
                   nu=false;
                   }
            }else if (expresia[i]=='}'){
                if(!simbolurile.empty() && simbolurile.top()=='{'){
                    simbolurile.pop();
                   c++;
                   } else {
                   nu=false;
                   }

            } else {
            nu=false;
            }



        }
            if(!simbolurile.empty())
        nu = false;

        if(nu){
            fout<<"DA"<<" ("<<a<<") "<<" ["<<b<<"] "<<" {"<<c<<"} "<<endl;
        } else {
            fout<<"NU"<<endl;
        }
        a=0;
        b=0;
        c=0;
        while(!simbolurile.empty()){
            simbolurile.pop();
        }

    }
}
