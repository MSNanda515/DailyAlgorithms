#include <iostream>

using namespace std;

int main(){
    string k;
    getline(cin, k);
    char cur = '\0';
    int maxRep = 0, rep = 0;  
    for (char c: k){
        if (c == cur){
            rep++;
        }
        else{
            if (rep > maxRep)
                maxRep = rep;
                rep = 1;
                cur = c;
        }
    }
    if (rep > maxRep)
        maxRep = rep;
    cout << maxRep << endl;
}