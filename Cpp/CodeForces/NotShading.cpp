#include <iostream>
#include <unordered_set>
using namespace std;


int main() {
	 int t;
	 cin >> t;
	 for (int i = 0; i < t; i++) {
	 	int n, m, r, c;
	 	cin >> n >> m >> r >> c;
	 	unordered_set<int> rows, cols;
	 	int ans = -2;
	 	for (int j = 0; j < n; j++) {
	 		for (int k = 0; k < m; k++) {
	 			char ch;
	 			cin >> ch;
	 			if (ch == 'B') {
	 				if (j+1 == r && k+1 == c) {
	 					ans = 0;
	 				}
	 				else {
	 					rows.insert(j+1);
	 					cols.insert(k+1);
	 				}
	 			}
	 		}
	 	}
	 	if (ans == -2) {
	 		if (ans == -2 && (rows.find(r) != rows.end() || cols.find(c) != cols.end())) {
	 		ans = 1;
	 	}
		 	else if (rows.size() > 0 || cols.size() > 0)
		 		ans = 2;
		 	else ans = -1;
	 	}
	 	
	 	cout << ans << '\n';
	 }
}