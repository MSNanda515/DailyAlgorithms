#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void sol(vector<int>& num, int x) {
    unordered_map<int, int> difPos;
    vector<int> sameDif;
    for (int i = 0; i < num.size(); i++) {
        difPos[x-num[i]] = i;
        if (x - num[i] == num[i]) {
            sameDif.push_back(i);
        }
    }
    for (int i = 0; i < num.size(); i++) {
        if (difPos.find(num[i]) != difPos.end()) {
            if (x - num[i] == num[i]) {
                if (sameDif.size() == 1) {
                    continue;
                } 
                cout << sameDif[0]+1 << ' ' << sameDif[1]+1 << '\n';
                return;
            }
            cout << i+1 << ' ' << difPos[num[i]] + 1 << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sol(num, x);
}