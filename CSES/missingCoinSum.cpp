
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

long sol(vector<int>& num) {
	sort(num.begin(), num.end());
	long res = 1;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] <= res) {
			res += num[i];
		} else {
			break;
		}
	}
	return res;
}

int main(){
	int t;
    cin >> t;
    vector<int> num;
    for (int i = 0; i < t; i++) {
   		int temp;
		cin >> temp;
		num.push_back(temp);
    }	
	cout << sol(num) << endl;	
}
