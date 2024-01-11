#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

vector<int> processLine(string& input) {
    stringstream ss(input);
    string token;
    vector<int> val;
    getline(ss, token, ' ');
    while (getline(ss, token, ' ')) {
        if (token.empty()) { continue; }
        val.push_back(stoi(token));
    }
    return val;
}

long processLine2(string& input) {
    stringstream ss(input);
    string token;
    vector<int> val;
    getline(ss, token, ' ');
    string numStr = "";
    while (getline(ss, token, ' ')) {
        if (token.empty()) { continue; }
        numStr += token;
    }
    return stol(numStr);
}

long findWays(vector<int>& dist, vector<int>& time) {
    long waysTot = 1, way = 0;
    for (int i = 0; i < dist.size(); i++) {
        way = 0;
        for (int j = 0; j < time[i]; j++) {
            int locDist = j * (time[i] - j);
            // cout << j << " " << locDist << " " << dist[i] << endl;
            if (locDist > dist[i]) {
                way++;
            }
        }
        // cout << way << " ";
        waysTot *= way;
    }
    return waysTot;
}

long findWays2(long time, long dist) {
    long way = 0;
    for (long j = 0; j < time; j++) {
        long locDist = j * (time - j);
        // cout << j << " " << locDist << " " << dist[i] << endl;
        if (locDist > dist) {
            way++;
        }
    }
    return way;
}

void sol() {
    string input;
    long cum = 0;
    getline(cin, input);
    long time = processLine2(input);
    getline(cin, input);
    long dist = processLine2(input);
    cout << findWays2(time, dist) << endl;
}

int main() {
    sol();
}