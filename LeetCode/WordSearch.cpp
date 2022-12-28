// https://leetcode.com/problems/word-search/description/
// Uses backtracking to prune useless branches

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
    vector<vector<short>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n = 0, m = 0;
    
    bool isValid(vector<vector<bool>>& avail, const int& r, const int& c) {
        if (r < 0 || r >= n || c < 0 || c >= m) {
            return false;
        }
        return avail[r][c];
    }

    bool explore(vector<vector<char>>& board, string& word, int ind, int r, int c, vector<vector<bool>>& avail) {
        // cout << "AA ";
        if (ind >= word.size()) {
            return true;
        }
        if (board[r][c] != word[ind]) {
            return false;
        }
        if (ind == word.size()-1) {
            return true;
        }
        // cout << r << c << endl;
        avail[r][c] = false;
        int newR, newC;
        bool found = false;
        for (int i = 0; i < dir.size() && !found; i++) {
            newR = r + dir[i][0];
            newC = c + dir[i][1];
            if (isValid(avail, newR, newC)) {
                found = found || explore(board, word, ind+1, newR, newC, avail);
            }
        }
        avail[r][c] = true;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        if (n == 0) {
            return false;
        }
        m = board[0].size();
        vector<vector<bool>> avail(n, vector<bool>(m, true));
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                found = found || explore(board, word, 0, i, j, avail);
            }
        }
        return found;
    }
};