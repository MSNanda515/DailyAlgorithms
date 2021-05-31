#include <iostream>
#include <string>
using namespace std;

int main() {
	string cipher;
	cin >> cipher;
	char postCipher[cipher.length()];
	for (int i=0;i<cipher.length(); i++){
		postCipher[i] = cipher[i] + 3;
		if (postCipher[i] > 'z')
			postCipher[i] = postCipher[i]-'z'+'a'-1;
		cout << postCipher[i];
		}
	cout << endl;
	
}
