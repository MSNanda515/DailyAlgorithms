#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void sol(vector<int>& sticks) {
    sort(sticks.begin(), sticks.end());
    int midEl = sticks.size() / 2;
    long diff = 0;
    for (int i = 0; i < sticks.size(); i++) {
        diff += abs(sticks[i] - sticks[midEl]);
    }
    cout << diff << endl;
}

int main(){
	int no;
    cin >> no;
    vector<int> sticks(no);
    for (int i = 0; i < no; i++) {
        int temp;
        cin >> temp;
        sticks[i] = temp;
    }
    sol(sticks);
}