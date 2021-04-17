#include  <iostream>
#include <string>
using namespace std;

int main(){
    string text;
    getline(cin, text);
    int noLo = 0, noUp = 0, noSp = 0, noChar;
    noChar = text.length();
    for(char c: text) {
        if (c == '_')
            noSp++;
        else if (c >= 'a' && c <= 'z')
            noLo ++;
        else if (c >= 'A' && c <= 'Z')
            noUp++;
        // else is a symbol
    }
    cout << noSp*1.0/noChar << '\n';
    cout << noLo*1.0/noChar << '\n';
    cout << 1.0*noUp/noChar << '\n';
    cout << 1.0*(noChar - noLo - noUp - noSp)/noChar << endl;
}