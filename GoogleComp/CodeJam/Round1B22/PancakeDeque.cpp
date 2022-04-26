#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>
#include <list>

using namespace std;

int sol(list<int>& del, int noPan) {
    int maxCur = 0;
    int pay = 0;
    while (del.size() > 0) {
        int l = del.front(), r = del.back();
        if (l < r) {
            del.pop_front();
            if (l >= maxCur) {
                pay++;
                maxCur = l;
            }
        } else {
            del.pop_back();
            if (r >= maxCur) {
                pay++;
                maxCur = r;
            }
        }
    }
    return pay;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int noPan;
        cin >> noPan;
        list<int> del;
        for (int i = 0; i < noPan; i++) {
            int temp;
            cin >> temp;
            del.push_back(temp);
        }

        cout << "Case #" << i+1 << ": " << sol(del, noPan) << '\n';
    }
}