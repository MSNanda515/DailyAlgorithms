#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

void sol() {
    int angle;
    cin >> angle;
    int hour = 0, min = 0;
    int diff;
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            hour = hour + 5;
            min = (60 + min) % 3600;
            if (hour <= min) {
                diff = min - hour;
            } else {
                diff = 3600 - hour + min;
            }
            if (diff == angle) {
                cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m+1 << "\n";
                return;
            }
        }
    }
    cout << -1;
}

int main(){
	sol();
}