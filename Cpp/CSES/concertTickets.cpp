#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    list<int> prices;
    vector<int*> p;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        prices.push_back(temp);
        p.push_back(prices.begin());
    }
    sort(prices.begin(), prices.end());
    unordered_set<int> sold;

    for (int i = 0; i < m; i++) {
        int maxBudget;
        cin >> maxBudget;
        int selInd;
        int lb = 0, ub = prices.size() - 1, flag = 0;
        
        while (lb <= ub) {
            int mid = (lb + ub) / 2;
            if (prices[mid] <= maxBudget) {
                if (sold.find(mid) == sold.end()) {
                    if (flag == 0) {
                    selInd = mid;
                    flag = 1;
                    }
                    else if (prices[mid] > prices[selInd]) {
                        selInd = mid;
                    }
                    lb = mid + 1;
                }
                else {
                    ub = mid - 1;
                }
            }
            else {
                ub = mid - 1;
            }
        }
        if (flag == 0) {
            // App ticket not found
            cout << -1 << '\n';
        }
        else {
            cout << prices[selInd] << '\n';
            sold.insert(selInd);
        }
    }

}
