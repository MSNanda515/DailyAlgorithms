#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

void sol(vector<vector<int>>& printers) {
    long double sumInks = 0;
    vector<int> minInk (4, 0);
    for (int i = 0; i < 4; i++) {
        int tempMin = printers[0][i];
        for (int j = 1; j < printers.size(); j++) {
            if (tempMin > printers[j][i]) {
                tempMin = printers[j][i];
            }
        }
        minInk[i] = tempMin;
        sumInks += tempMin;
    }
    if (sumInks < 1e6) {
        cout << " IMPOSSIBLE\n";
        return;
    }
    long double excess = sumInks - 1e6;
    for (int i = 0; i < 4; i++) {
        if (minInk[i] < excess) {
            excess -= minInk[i];
            minInk[i] = 0;
        }
        else {
            minInk[i] -= excess;
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << " " << minInk[i];
    }
    cout << "\n";
    // sumInks = 0;
    // for (int i = 0; i < 4; i++) {
    //     sumInks += minInk[i];
    // }
    // cout << sumInks << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        vector<vector<int>> inks(3, vector<int>(4, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                int temp;
                cin >> temp;
                inks[i][j] = temp;
            }
        }
        cout << "Case #" << k + 1 << ":";
        sol(inks);
    }
}