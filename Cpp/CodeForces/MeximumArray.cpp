#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		int n;
		cin >> n;
		vector<vector<int> > occ(n+2);
		vector<int> ar(n+1);
		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			ar[i] = temp;
			occ[ar[i]].push_back(i);
		}
		vector<int> b;
		int l = 1;
		while (l <= n) {
			int mex = 0;
			int r = l;
			for (; mex <= n+1; mex++) {
				auto it = lower_bound(occ[mex].begin(), occ[mex].end(), l);
				if (it == occ[mex].end()) {
					break;
				}
				r = max(*it, r);
			}
			b.push_back(mex);
				// break;
			l = r + 1;
		}
		cout << b.size() << '\n';
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << ' ';
		}
		cout << '\n';
	}

}