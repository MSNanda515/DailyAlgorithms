#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    multiset<int> prices;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        prices.insert(temp);
    }

    for (int i = 0; i < m; i++) {
        int budget;
        cin >> budget;
        auto it = prices.upper_bound(budget);
        if (it == prices.begin()) {
            cout << "-1" << '\n';
        }
        else {
            cout << *(--it) << '\n';
            prices.erase(it);
        }
    }

}