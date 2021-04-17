#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	char prog[n];
	cin >> prog;
	stack<char> myColl;
	char ch, ch1;
	for(int i=0; i<n; i++){
		ch = prog[i];
		if (ch=='(' || ch=='{' || ch=='['){
			myColl.push(ch);
		}
		else if(ch==')'||ch=='}'||ch==']'){
			ch1 = myColl.top();
			if (ch1=='(' && ch!=')') {
				cout<<") "<<i<<endl;
				break;

			}
			else if(ch1=='{' && ch!='}'){
				cout << "} "<<i<<endl;
				break;
			}
			else if(ch1=='[' && ch!=']'){
				cout << "] "<<i<<endl;
				break;
			}
			else
				myColl.pop();
		}
		if (i==n-1)
			cout <<"ok so far"<<endl;
	}
}
