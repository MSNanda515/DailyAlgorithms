#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>


using namespace std;

struct dec1 {
    int drop;
    int dist;
    dec1() {
        drop = dist = 0;
    }
    
    dec1(int dr, int di) {
        drop = dr; dist = di;
    }
};

bool dec1Sorter(dec1& d1, dec1&d2) {
    if (d1.dist != d2.dist) {
        return d1.dist < d2.dist;
    }
    return d1.drop > d2.drop;
}

vector<int> getMinEachCat(vector<vector<int>>& exer, int& e, int& w) {
    vector<int> minCat(w);
    for (int i = 0; i < w; i++) {
        int tempMin = exer[0][i];
        for (int j = 0; j < e; j++) {
            if (tempMin > exer[j][i]) {
                tempMin = exer[j][i];
            }
        }
        minCat[i] = tempMin;
    }
    return minCat;
}

int makeChanges(vector<int>& curStat, stack<int>& machine, vector<vector<int>>& exer, int curIndex, int& e, int& w) {
    int moves = 0;
    vector<dec1> rem(w, dec1());
    for (int i = 0; i < w; i++) {
        for (int j = curIndex+1; j < e; j++) {
            if (exer[j][i] < exer[curIndex][i]) {
                rem[i].dist = j - curIndex;
                rem[i].drop = exer[j][curIndex] - exer[j][i];
                break;
            }
        }
    }
    sort(rem.begin(), rem.end(), &dec1Sorter);
    
}

int sol(vector<vector<int>>& exer, int& e, int& w) {
    stack<int> machine;
    int totMoves = 0;

    vector<int> curStat = getMinEachCat(exer, e, w);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < curStat[i]; j++) {
            totMoves++;
            machine.push(i);
        }
    }

    for (int i = 0; i < e; i++) {

    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int e, w, temp;
        cin >> e >> w;
        vector<vector<int>> exer(e, vector<int>(w));
        for (int i = 0; i < e; i++) {
            for (int j = 0; j < w; j++) {
                cin >> temp;
                exer[i][j] = temp;
            }
        }
        cout << "Case #" << k + 1 << ": " << sol(exer, e, w) << '\n';
    }
}