#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

struct node {
	int ramReq;
	int ramInc;
	node(int a, int b = 0) {
		ramReq = a;
		ramInc = b;
	}
};

bool comSmall(const node& a, const node& b) {
	return a.ramReq < b.ramReq;
}
// bool comBig(const node*& a, const node*& b) {
// 	return a->ramReq > b->ramReq;
// }

struct comBig {
	bool operator() (const node*& a, const node*& b) {
		return a->ramReq > b->ramReq;
	}
};

struct greaters{ 
bool operator()( node*& a,  node*& b) const{ 
    return a->ramReq > b->ramReq; 
} 
}; 

int findMaxRam() {
	int n, k;
	vector<node*> ram;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		node* tempNode = new node(temp);
		ram.push_back(tempNode);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ram[i]->ramInc = temp;
	}

	make_heap(ram.begin(), ram.end(), greaters());

	for (int i = 0; i < n; i++) {
		node* it = ram[0];
		// cout << it->ramReq << ' ';
		// cout << it->ramReq << ' ' << k << ' ';
		if (it->ramReq > k) {
			break;
		}

		k += (it)->ramInc;
		// cout << k << '\n';
		pop_heap(ram.begin(), ram.end(), greaters());
		ram.pop_back();
	}
	// for (int i = 0; i < n; i++) {
	// 	cout << ram[i]->ramReq << ' ';
	// }
	// cout << '\n';

	return k;

	
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << findMaxRam() << '\n';
	}
}