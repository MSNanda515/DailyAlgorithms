#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>


using namespace std;


class Solution {
    // returns true if able to find path from source to sink
    bool bfs(vector<vector<int>>& graph, int source, int target, vector<int>& parents) {
        queue<int> qu;
        qu.push(source);
        int n = graph.size() - 1;
        vector<bool> visited(n+1, false);
        parents[source] = source;

        while(!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            visited[cur] = true;

            for (int i = 1; i <= n; i++) {
                if (visited[i] == false && graph[cur][i] > 0) {
                    parents[i] = cur;
                    if (i == target) {
                        return true;
                    }
                    qu.push(i);
                }
            }
        }
        return false;
    }

public:
    int solve(int N,int M,vector<vector<int>>& edges) {
        vector<vector<int>> graph(N+1, vector<int>(N+1, 0));
        vector<int> parents(N+1, 0);
        int maxFlow = 0;

        for (int i = 0; i < M; i++) {
            int v1 = edges[i][0], v2 = edges[i][1], fl = edges[i][2];
            graph[v1][v2] = fl;
            graph[v2][v1] = fl;
        }

        int i = 0;
        while(bfs(graph, 1, N, parents)) {
            int minFlow = 1e9;
            int ptr = N;
            while (ptr != 1) {
                int pa = parents[ptr];
                if (graph[pa][ptr] < minFlow) {
                    minFlow = graph[pa][ptr];
                }
                ptr = pa;
            }

            for (ptr = N; ptr != 1; ptr = parents[ptr]) {
                int pa = parents[pa];
                graph[pa][ptr] -= minFlow;
                graph[ptr][pa] += minFlow;
            }
            maxFlow += minFlow;
            // i++;
            // if (i == 20)
            //     break;
        }
        // cout << "GOOD so far" << endl;
        return maxFlow;
    }
};

int main()
{
    int i,j,N,M,u,v,w;
    int res;
    // scanf("%d %d",&N,&M);
    cin >> N >> M;
    vector<vector<int>> Edges; 
    for(i=0;i<M;i++)
    {
        cin >> u >> v >> w;
        // scanf("%d %d %d",&u,&v,&w);
        Edges.push_back({u,v,w});
    }
    Solution obj;
    // cout << N << " " << M;
    res = obj.solve(N, M, Edges);
    cout<<res<<endl;
    
}