#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0);
	cin.tie(0); // see Fast Input & Output
	// alternatively, cin.tie(0)->sync_with_stdio(0);
	if (name.size() > 0) {
		freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void sol() {

}

int main(){
    setIO("teleport");
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<int> comb;
    comb.push_back(abs(b-a));
    comb.push_back(abs(a-x)+abs(b-y));
    comb.push_back(abs(a-y)+abs(b-x));
    int minDist = abs(b-a);
    for (auto i : comb) {
        minDist = min(i, minDist);
    }
    cout << minDist << endl;
}