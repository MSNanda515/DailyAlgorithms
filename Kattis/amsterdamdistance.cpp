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
    int m, n;
    cin >> m >> n;
    double rad;
    cin >> rad;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double minDist = INT_MAX;
    double ringDist = rad / n;
    double segAng = M_PI / m * abs(x2 - x1);
    double curDist;

    for (int r = y1; r >= 0; r--) {
        curDist = abs(y1-r) * ringDist;
        curDist += segAng * r * ringDist;
        curDist += abs(r-y2) * ringDist;
        minDist = min(minDist, curDist);
    }
    cout << setprecision(15) << minDist << "\n";
}

int main(){
	sol();
}