#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> record;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (record.find(temp) == record.end()) {
            // The no isn't in the set
            record.insert(temp);
            counter++;
        }
    }
    cout << counter << endl;
}