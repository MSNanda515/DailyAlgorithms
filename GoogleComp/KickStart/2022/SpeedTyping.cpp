#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int sol(string& I, string& P) {
    int indI = 0, indP = 0;
    int sizeI = I.size(), sizeP = P.size();
    if (sizeI > sizeP) {
        return -1;
    }
    int del = 0;
    while (indI < sizeI && indP < sizeP) {
        if (I[indI] != P[indP]) {
            indP++;
            del++;
        } else {
            indI++;
            indP++;
        }
    }
    if (indI == sizeI) {
        while (indP < sizeP) {
            del++;
            indP++;
        }
        return del;
    }

    return -1;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string I, P;
        cin >> I >> P;
        int del = sol(I, P);
        // Case #1: 1
        cout << "Case #" << i+1 << ": ";
        if (del == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << del << '\n';
        }
    }
}