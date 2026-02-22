#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int toarab(const string &k, int &s, const map<char, int> &chartoint);

int main() {
    ifstream fin("roman.in");
    ofstream fout("roman.out");

    string text;
    map<char, int> trad = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    while(getline(fin, text)) {
        int s = -1;
        int result = toarab(text, s, trad);

        while(s + 1 < text.length()) {
            char op = text[s + 1];
            if(op != '+' && op != '-') break;
            s++;
            int next = toarab(text, s, trad);
            if(op == '+') result += next;
            else result -= next;
        }

        fout << result;
    }
}

int toarab(const string &k, int &s, const map<char, int> &chartoint) {
    int a = 0;
    for(int i = s + 1; i < k.length(); i++) {

        if(chartoint.find(k[i]) == chartoint.end()) {
            s = i - 1;
            break;
        }

        if(i + 1 < k.length() && chartoint.find(k[i+1]) != chartoint.end() && chartoint.at(k[i]) < chartoint.at(k[i+1])) {
            a += chartoint.at(k[i+1]) - chartoint.at(k[i]);
            i++;
        }

        else if(i + 2 < k.length() && chartoint.find(k[i+1]) != chartoint.end() && chartoint.find(k[i+2]) != chartoint.end()
                && chartoint.at(k[i]) == chartoint.at(k[i+1]) && chartoint.at(k[i]) == chartoint.at(k[i+2])) {
            a += chartoint.at(k[i]) + chartoint.at(k[i+1]) + chartoint.at(k[i+2]);
            i += 2;
        }

        else if(i + 1 < k.length() && chartoint.find(k[i+1]) != chartoint.end() && chartoint.at(k[i]) == chartoint.at(k[i+1])) {
            a += chartoint.at(k[i]) + chartoint.at(k[i+1]);
            i++;
        }
        else {
            a += chartoint.at(k[i]);
        }

        s = i;
    }
    return a;
}
