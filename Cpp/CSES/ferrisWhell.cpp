#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long n, x;
    cin >> n >> x;
    vector<long> weights;
    for (long i = 0; i < n; i++) {
        long temp;
        cin >> temp;
        weights.push_back(temp);
    }
    sort(weights.begin(), weights.end());

    auto startChild = weights.begin();
    auto endChild = weights.end() - 1;
    long gond = 0;
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