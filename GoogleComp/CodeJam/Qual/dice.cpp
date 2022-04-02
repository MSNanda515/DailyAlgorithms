#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

int sol(vector<int> dice, int noDice, int maxVal, int minVal) {
    if (minVal >= noDice) {
        return noDice;
    }

    int str = 0;

    vector<int> opt (maxVal+1, 0);
    sort(dice.begin(), dice.end());
    int ptrDice = 0;
    for (int i = 1; i <= maxVal; i++) {
        if (i > dice[ptrDice]) {
            while (ptrDice < noDice && i > dice[ptrDice]) {
                ptrDice++;
            }
        }
        opt[i] = noDice - ptrDice;
    }

    int curSt = 0;
    for (int i = maxVal; i >= 1; i--) {
        curSt++;
        if (curSt > opt[i]) {
            curSt = opt[i];
        }
        if (str < curSt) {
            str = curSt;
        }
        
    }
    return str;
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int noDice = 0;
        cin >> noDice;
        vector<int> dice (noDice, 0);
        int minVal = 1e5, maxVal = 0;
        for (int i = 0; i < noDice; i++) {
            int temp;
            cin >> temp;
            dice[i] = temp;
            if (temp < minVal)
                minVal = temp;
            if (temp > maxVal)
                maxVal = temp;
        }

        cout << "Case #" << k + 1 << ": " << sol(dice, noDice, maxVal, minVal) << '\n';
    }
}