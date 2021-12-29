#include <iostream>
#include <unordered_map>

using namespace std;

int c = 0;

void minDiffSet(unordered_map<int, int>& bag1, unordered_map<int, int>& bag2,
                unordered_map<int, int> left, long& minDif) {
    c++;
    if (left.size() == 0) {
        long sum1 = 0, sum2 = 0;
        for (auto it : bag1)
            sum1 += it.second;
        for (auto it : bag2)
            sum2 += it.second;
        if (minDif > abs(sum1 - sum2) || minDif < 0) {
            minDif = long(abs(sum1-sum2));
        }
        return;
    }
    unordered_map<int, int> copyLeft;
    for (auto it : left) {
        copyLeft[it.first] = it.second;
    }

    for (auto it : copyLeft) {
        left.erase(it.first);
        // Insert the entry in the two bags and experiment
        bag1[it.first] = it.second;
        minDiffSet(bag1, bag2, left, minDif);
        bag1.erase(it.first);
        bag2[it.first] = it.second;
        minDiffSet(bag1, bag2, left, minDif);
        bag2.erase(it.first);
    }
}

int main() {
    int n, temp;
    cin >> n;
    unordered_map<int, int> left;
    unordered_map<int, int> bag1;
    unordered_map<int, int> bag2;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        left[i] = temp;
    }
    long minDiff = -1;
    minDiffSet(bag1, bag2, left, minDiff);
    cout << minDiff << endl;
    cout << c <<endl;
}