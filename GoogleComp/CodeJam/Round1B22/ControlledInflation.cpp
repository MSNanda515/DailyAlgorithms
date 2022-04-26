#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>

using namespace std;

long makeMove(int curPres, vector<int>& choice, int ind, vector<vector<int>>& pres) {
    long move = 0;
    for (int i = 0; i < choice.size(); i++) {
        move += abs(pres[ind][choice[i]] - curPres);
        curPres = pres[ind][choice[i]];
    }
    return move;
}

long expSol(vector<vector<int>>& pres, int ind, long moves, int curPres, vector<vector<long>>& dp) {
    if (ind == pres.size()) {
        return moves;
    }
    if (dp[ind][0] == curPres && dp[ind][1] > 0) {
        return moves + dp[ind][1];
    }
    vector<int> c1 = {0, 1}, c2 = {1, 0};
    long m1 = makeMove(curPres, c1, ind, pres);
    long m2 = makeMove(curPres, c2, ind, pres);
    m1 = expSol(pres, ind+1, moves+m1, pres[ind][c1[1]], dp);
    m2 = expSol(pres, ind+1, moves+m2, pres[ind][c2[1]], dp);
    long ans = min(m1, m2);
    dp[ind] = {curPres, ans - moves};
    return ans;
}

long sol(vector<vector<int>>& pres) {
    vector<vector<long>> dp(pres.size(), {0, 0});
    return expSol(pres, 1, 0, 0, dp);
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, p;
        cin >> n >> p;
        vector<vector<int>> pres(n+1);
        pres[0] = {0, 0};
        for (int i = 1; i <= n; i++) {
            int minP = 1e9, maxP = 0;
            for (int j = 0; j < p; j++) {
                int temp;
                cin >> temp;
                if (temp < minP) {
                    minP = temp;
                } 
                if (temp > maxP) {
                    maxP = temp;
                }
            }
            pres[i] = {minP, maxP};
        }
        cout << "Case #" << i+1 << ": " << sol(pres) << '\n';
    }
}