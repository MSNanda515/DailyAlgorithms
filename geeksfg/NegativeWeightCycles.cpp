/**
 * Using Bellman Ford Algorithm, the shortest distance is found from the source to each vertex
 * by relaxing each edge a maximum of V-1 times. 
 * Check for negative cycles is made by seeing if any edge can be relaxed further after the above process
 * */

// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, 1e8);
        dist[0] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if (dist[u] != 1e8 && dist[v] > dist[u] + w) {
                    // relax the edge
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[v] > dist[u] + w) {
                return 1;
            }
        }
        return 0;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}