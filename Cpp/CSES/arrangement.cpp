#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int a = m / n;
	int b = m % n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < a; j++)
			cout << '*';
		if (i < b)
			cout << '*';
		cout << endl;
	}
}