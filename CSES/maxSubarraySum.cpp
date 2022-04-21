// https://cses.fi/problemset/task/1643
// Used Kadane's algorithm to find the sum of the maximum subarray

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void sol(vector<int>& num) {
    long long maxSum = 0, tempSum = 0;
    for (int i = 0; i < num.size(); i++) {
        if (tempSum + num[i] > 0) {
            tempSum += num[i];
            if (tempSum > maxSum) {
                maxSum = tempSum;
            }
        } else {
            tempSum = 0;
        }
        // cout << tempSum << ' ' << num[i] << '\n';
    }
    if (maxSum > 0) {
        cout << maxSum << endl;
    } else {
        int maxEl = num[0];
        for (int i = 0; i < num.size(); i++) {
            if (maxEl < num[i]){
                maxEl = num[i];
            }
        }
        cout << maxEl << endl;
    }
}

int main(){
	int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sol(num);
}