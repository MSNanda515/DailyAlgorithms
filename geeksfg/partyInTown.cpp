#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution{
    void dfs(int v, int u, vector<int>& dist, vector<vector<int>>& adj) {
        for (auto to : adj[v]) {
            if (to == u) {
                continue;
            }
            dist[to] = dist[v] + 1;
            dfs(to, v, dist, adj);
        }
    }
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
        int minDist = 1e9 + 7;
        for (int i = 1; i <= N; i++) {
            vector<int> dist(N+1, 0);
            dfs(i, 0, dist, adj);
            int maxDist = 0;
            for (int j = 1; j <= N; j++) {
                maxDist = max(maxDist, dist[j]);
            }
            minDist = min(minDist, maxDist);
        }
        return minDist;
    }
    
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}