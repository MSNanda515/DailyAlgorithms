#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

void checkConn(string* map, int r, int c, int row, int col, unordered_map <int, unordered_set<int> >& graph) {
  int dir[][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
  int conR, conC;
  for (int k = 0; k < 4; k++) {
    conR = row + dir[k][0];
    conC = col + dir[k][1];
    if (conR < 0 || conC < 0 || conR >= r || conC >= c)
      // Out of bounds
      continue;
    if (map[row][col] == map[conR][conC]) {
      // connected
      graph[row*c + col].insert(conR*c + conC);
    }
  }
}

void printGraph(unordered_map<int, unordered_set<int> >& graph) {
  for (auto it = graph.begin(); it != graph.end(); it++) {
    cout << it->first << " : ";
    for (auto el = it->second.begin(); el != it->second.end(); el++) {
      cout << *el << " ";
    }
    cout << endl;
  }
}

int main () {
  // receive and process the input
  int r, c;
  cin >> r >> c;
  unordered_map <int, unordered_set<int> > graph;
  string map[r];
  for (int i = 0; i < r; i++) {
    cin >> map[i];
    for (int j = 0; j < c; j++){
      // initialize the entry in the array
      graph[i * c + j];
    }
  }

  // Make the graph of the strings
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++) {
      checkConn(map, r, c, i, j, graph);
    }
  }

  printGraph(graph);
}