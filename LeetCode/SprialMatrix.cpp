// https://leetcode.com/problems/spiral-matrix/description/
// Traverses matrix in the given direction
// uses n^2 space, n^2 time

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {

    bool validMove(const int& r, const int& c, const int& n, const int& m, 
        vector<vector<bool>>& visited) {
        if (r < 0 || c < 0 || r >= n || c >= m) {
            return false;
        }
        return !visited[r][c];
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int n = matrix.size(), m = matrix[0].size();
        if (n == 0 || m == 0) return {};
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        vector<int> ans;
        int cur = 0;
        int r = 0, c = 0, newR, newC;
        for (int i = 0; i < n*m; i++) {
            if (validMove(r, c, n, m, visited)) {
                ans.push_back(matrix[r][c]);
            }
            
            visited[r][c] = true;
            newR = r + dir[cur][0];
            newC = c + dir[cur][1];
            if (validMove(newR, newC, n, m, visited)) {
                r = newR; c = newC;
            } else {
                cur = (cur+1) % 4;
                newR = r + dir[cur][0];
                newC = c + dir[cur][1];
                r = newR; c = newC;
            }
        }
        return ans;
    }
};