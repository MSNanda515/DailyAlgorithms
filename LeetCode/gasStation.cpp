
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

using namespace std;

int main() {
	
}

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	long long total = 0, avail = 0;
	int ind = 0;
	for (int i = 0; i < gas.size(); i++) {
		total += gas[i] - cost[i];
		avail += gas[i] - cost[i];
		if (avail < 0) {
			avail = 0;
			ind = i + 1;
		} 
	}
	return (total < 0) ? -1 : ind;
    }
};

