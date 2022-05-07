// https://practice.geeksforgeeks.org/problems/kill-captain-america0228/1#
// Uses the observation that as long we have root nodes (nodes which cannot be reached by any 
// other node), we can remove that and the remaining nodes should contain the nodes that are
// reachable by all other nodes. Edge case: if we have only one terminal node, no cycles, 
// in that case the answer will be 1

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        // Code Here
        int n = N;
        vector<vector<int>> adj(N);
        vector<int> inlet(n, 0);
        
        // Prepare the adjacency list for the graph
        // also find the number of connections to each node
        for (int i = 0; i < M; i++) {
            int f = V[i][0]-1, t = V[i][1]-1;
            adj[f].push_back(t);
            inlet[t]++;
        }
        
        // find the terminal nodes and account for the edge case,
        // Also push the root nodes in the queue
        queue<int> q;
        int term = -1;
        bool termExists = true;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 0) {
                if (term == -1) term = i;
                else termExists = false;
            }
            if (inlet[i] == 0) {
                q.push(i);
            }
        }
        if (termExists && term != -1) return 1;
        
        // Remove root nodes, and continue as long the remaining nodes have a root node
        while (q.size() > 0) {
            n--;
            int root = q.front();
            q.pop();
            for (int i = 0; i < adj[root].size(); i++) {
                int& to = adj[root][i];
                inlet[to]--;
                if (inlet[to] == 0) {
                    q.push(to);
                }
            }
        }
        return n;
    } 
};

// { Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}