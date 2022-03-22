#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		if (l == r && l > 1) {
			cout << "YES\n";
		}
		else {
			int minMoves;
			if (l % 2 != 0 && r % 2 != 0) {
				minMoves = floor((r - l + 1) / 2) + 1;
			}
			else {
				minMoves = floor((r - l + 1) / 2);
			}
					if (minMoves > k)
						cout << "NO\n";
					else
						cout << "YES\n";
		}

	}
}