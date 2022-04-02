#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

void sol(int r, int c) {
    int row, col;
    for (int i = 0; i < r; i++) {
        if (i == 0) {
            col = c - 1;
            cout << "..";
        }
        else {
            col = c;
        }
        for (int j = 0; j < col; j++) {
            cout << "+-";
        }
        cout << "+\n";
        if (i == 0) {
            cout << "..";
        }
        for (int j = 0; j < col; j++) {
            cout << "|.";
        }
        cout << "|\n";
    }

    for (int j = 0; j < c; j++) {
        cout << "+-";
    }
    cout << "+\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;
        cout << "Case #" << i+1 << ":\n";
        sol(r, c);
    }
}