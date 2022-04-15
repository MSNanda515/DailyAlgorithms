// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#
// done following the kadane's algorithm and extending for 2D matrix
// Can be optimized further by keeping the minimum dimension as C using Transpose of matrix.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int result = -1;
        vector<int> sumRows(R);
        for (int i = 0; i < C; i++) {
            for (int k = 0; k < R; k++) {
                sumRows[k] = 0;
            }
            for (int j = i; j < C; j++) {
                int curSum = 0;
                for (int k = 0; k < R; k++) {
                    sumRows[k] += M[k][j];
                    curSum = max(sumRows[k], curSum +sumRows[k]);
                    result = max(result, curSum);
                }
                
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}