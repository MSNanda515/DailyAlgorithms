#include <iostream>
#include <set>

using namespace std;

int main() {
    long n;
    cin >> n;
    set<int> bag;
    long temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        bag.insert(temp);
    }
    cout << bag.size() << '\n';
}