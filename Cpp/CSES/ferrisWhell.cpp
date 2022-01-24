#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }
    sort(weights.begin(), weights.end());

    auto startChild = weights.begin();
    auto endChild = weights.end() - 1;
    int gond = 0;
    while(startChild <= endChild) {
        if ((*startChild) + (*endChild) <= x) {
            startChild++;
        }
        endChild--;
        gond++;
    }
    cout << gond << endl;
    return 0;
}