#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSum(int n) {
    vector<int> digs;
    int cumSum = 0;
    int lastDig = 0, curDig;
    if ((n - 2) % 3 == 0) {
        lastDig = cumSum = 2;
    }
    else {
        lastDig = cumSum = 1;
    }
    digs.push_back(lastDig);

    while (cumSum < n) {
        if (lastDig == 1)
            curDig = 2;
        else 
            curDig = 1;
        
        cumSum += curDig;
        digs.push_back(curDig);
        lastDig = curDig;
    }
    return digs;
}

        
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> digs = maxSum(n);
        if (digs.back() == 2) {
            for (int i = 0; i < digs.size(); i++) {
                cout << digs[digs.size() - 1 - i];
            }
        }
        else {
            for (int i = 0; i < digs.size(); i++) {
                cout << digs[i];
            }
        }
        cout << '\n';
    }
}