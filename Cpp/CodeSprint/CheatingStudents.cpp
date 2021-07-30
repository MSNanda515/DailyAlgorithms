/*
	Contains an implementation of Kruskal's MST algorithm using the
	union-find data structure.

	Zac Friggstad, 2021

	Reads input in the format:

	First line:
	n m
	(n == # nodes, m = # edges)

	Then m lines follow, each of the form
	u v c
	describing an edge connecting u to v with cost c.

	The vertices are assumed to be labelled from 0 to n-1.

	You can put extra comments at the bottom of a .txt file containing the
	description of a graph, they will not be read by this program.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

/*
	To model an edge (mainly for sorting them by cost)
*/
struct Edge {
	int u, v, cost;
	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}
};


#include <cassert>

#include <unordered_map>

using namespace std;

class UnionFind {
public:
	// A constructor is not necessary, the parent and rank
	// mappings will just be empty upon initialization.

	// Adds an item to the data structure, if it was there already
	// then this does nothing (it does not change the partition).
	// If not, it is added as a singleton part {v} in the partition.
	void add_item(int v);

	// Find the representative for the set containing u.
	int find(int u);

	// Merge the sets, returns true iff the merge was successful
	// (i.e. they were not in the same set already).
	// Cannot use the function name "union" :(  It is a keyword in c++.
	bool merge(int u, int v);

private:
	// maps an item to its parent
	unordered_map<int, int> parent;

	// maps an item to its rank
	unordered_map<int, int> rank;
};
void UnionFind::add_item(int v) {
	if (parent.find(v) == parent.end()) {
		parent[v] = v;
		rank[v] = 0;
	}
}

// CHALLENGE: incorporate path compression for a small speedup.
// Requires replacing the loop with recursion.
int UnionFind::find(int v) {
	// make sure v is in the data structure
	assert(parent.find(v) != parent.end());

  while (v != parent[v]) {
    v = parent[v];
  }

  return v;
}

bool UnionFind::merge(int u, int v) {
	int rep_u = find(u), rep_v = find(v);

	// already in same component
	if (rep_u == rep_v) {
		return false;
	}

	// redirect the smaller rank to point to the larger rank
	if (rank[rep_u] < rank[rep_v]) {
		parent[rep_u] = rep_v;
	}
	else if (rank[rep_u] > rank[rep_v]) {
		parent[rep_v] = rep_u;
	}
	else {
		// if ranks are the same, point rep_u to rep_v and increase the rank of rep_v
		parent[rep_u] = rep_v;
		rank[rep_v]++;
	}

	return true;
}


struct coord{
    int x, y;
};

int dist(coord& c1, coord& c2 ) {
    return abs(c1.x - c2.x) + abs(c1.y-c2.y);
}

int main() {
	// n == number of nodes
	int n, m;
	cin >> n;
    vector<coord> st;
    int x, y;
    for (int i = 0; i < n; i++){
        coord c;
        cin >> c.x >> c.y;
        st.push_back(c);
    }
	// cout << "ST Size " <<st.size() << endl;

	// Read in the vertices and initialize the union find data structure
	// by adding all vertices one at a time.
	UnionFind uf;
	for (int i = 0; i < n; ++i) {
		uf.add_item(i);
	}

	// Read in the edges.
	vector<Edge> edges;

	// Declaring this by reference allows us to read directly into the vector.
	// This is equivalent to
	// for (int i = 0, i < m; i++) {
	//   cin >> e[i].u >> e[i].v >> e[i].cost;
	// }
    for (int i = 0; i < n; i++) {
        for (int j = i ; j < n; j++) {
            Edge e;
            e.u = i;
            e.v = j;
            e.cost = dist(st[i], st[j]);
			edges.push_back(e);
        }
    }
	// Kruskal's algorithm, first sort them in increasing order of cost.
	sort(edges.begin(), edges.end());

	// Then try merging the components by processing the edges in order of cost.
	// Every successful merge means we bridge two previously-disconnected
	// components so we should add the edge to the MST we are building.
	vector<Edge> mst;
	int mstCost = 0;
	for (Edge e : edges) {
		if (uf.merge(e.u, e.v)) {
			mst.push_back(e);
			mstCost += e.cost;
		}
	}
	// cout << "Edges Size" << edges.size();
	cout << 2 * mstCost << endl;
	// cout << "Edges:" << endl;
	// for (Edge e : mst) {
	// 	cout << "(" << e.u << "," << e.v << ") - with cost: " << e.cost << endl;
	// }

	return 0;
}
