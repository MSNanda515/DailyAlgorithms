#include <iostream>

using namespace std;

bool debug = false;

int main(){
	int n;
	cin >> n;
	int steps[n];
	for(int i = 0; i < n; i++) {
		int entry;
		cin >> entry;
		int ar;
		int max = 0, min;
		for (int j = 0; j < entry; j++){
			cin >> ar;
			if (j==0)
				min = ar;
			if (ar > max)
				max = ar;
			if (ar < min)
				min = ar;
		}
		if (debug)
			cout <<min << ' ' << max << endl;
		steps[i] = 2*(max-min);
	}
	for (int j = 0; j < n; j++)
		cout << steps[j] << endl;
	
}
