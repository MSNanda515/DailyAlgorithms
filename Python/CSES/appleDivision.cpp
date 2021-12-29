#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weight;
    int temp;
    long totSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        totSum += temp;
        weight.push_back(temp);
    }
    long minDiff = LONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        long bag1Sum = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                 bag1Sum += weight[j];
            }
        }
        if (abs(totSum - 2*bag1Sum) < minDiff)
            minDiff = abs(totSum - 2*bag1Sum);
    }
    cout << minDiff << endl;
}
