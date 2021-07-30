#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void DFS(unordered_map<int, unordered_set<int> > & islands, int start, 
    unordered_set<int>& visited){
        if (visited.find(start) != visited.end()) {
            return;
        }
        visited.insert(start);
        for (auto it = islands[start].begin(); it != islands[start].end(); it++){
            DFS(islands, *it, visited);
        }
}

int main () {
    unordered_map<int, unordered_set<int> > islands;
    unordered_set<int> visited;
    int n;
    long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        // Create the entry in the map
        islands[i];
    }
    int temp1, temp2;
    for (long i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        islands[temp1].insert(temp2);
        islands[temp2].insert(temp1);
    }
    DFS(islands, 1, visited);
    int flag = 0;
    for (int i = 1; i <= n; i++){
        if (visited.find(i) == visited.end()){
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        // not connected
        cout << "NO" << endl;
    }
    else {
        // connected
        cout << "YES" << endl;
    }



}