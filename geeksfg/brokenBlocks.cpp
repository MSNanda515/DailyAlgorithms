//https://practice.geeksforgeeks.org/problems/broken-blocks0022/1
// Uses DP to find the ideal block to come from the previous level
// Time complexity: O(n*m)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int m = matrix.size(), n = matrix[0].size();
    int maxG = 0;
    vector<int> dp(matrix[0].size(), 0), dp1(n);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < n; j++) {
            int prevG = -1;
            for (int k = max(0, j-1); k <= min(n-1, j+1); k++) {
                prevG = max(prevG, dp[k]);
            }
            if (matrix[i][j] == -1) {
                maxG = max(prevG, maxG);
                dp1[j] = -1;
                continue;
            }
            if (prevG == -1) {
                dp1[j] = -1;
            } else {
                dp1[j] = prevG + matrix[i][j];     
            }
        }
        int foundPos = false;
        for (int j = 0; j < n; j++) {
            dp[j] = dp1[j];
            if (dp[j] > -1) {
                foundPos = true;
            }
            // cout << dp[j] << ' ';
        }
        if (!foundPos) {
            break;
        }
        // cout << endl;
    }
    for (int j = 0; j < n; j++) {
        maxG = max(maxG, dp[j]);
    }
    return maxG;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}