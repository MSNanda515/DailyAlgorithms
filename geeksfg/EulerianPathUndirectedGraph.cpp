#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
        int oddEdges = 0;
        for (int i = 0; i < N; i++) {
            int edge = 0;
            for (int j = 0; j < N; j++) {
                if (graph[i][j] == 1) {
                    edge++;
                }
            }
            if (edge % 2 != 0) {
                oddEdges++;
            }
        }
        if (oddEdges == 0 || oddEdges == 2) {
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                cin>>graph[i][j];
        
        Solution ob;
        cout<<ob.eulerPath(N, graph)<<"\n";
    }
    return 0;
}