#include <iostream>
#include <string>
using namespace std;

long factorial(int no){
	long fact = 1;
	for (int i= 2; i<=no; i++)
		fact *= i;
	return fact;
}
long comb(int n, int m){
	long combination = factorial(n)/(factorial(m)*factorial(n-m));
	return combination;
}

long maxShift(char* ar,int  n){
	long shift = 0, one = 0, q=0, tempOne;
	int j;
	for (int i =0; i<=n; i++){
		if (ar[i] == '1')
			one++;
		else if(ar[i] == '0' || ar[i] == '?')
		{
			if (ar[i] == '?')
				shift+=shift;
			tempOne = one;
			for(j=0; j<=q; j++){
				shift += tempOne*comb(q,j);
				tempOne++;				
			}
		}
		if(ar[i] == '?')
			q++;
	}
	return shift;
}
int main () {
	string seq;
	cin >> seq;
	long lenSeq = seq.length();
	long swaps = 0;
	char tempSeq[lenSeq];
	for (int i = 0; i<lenSeq; i++){
		tempSeq[i] = seq[i];
	}
	cout << maxShift(tempSeq, lenSeq)<<endl;
}
