#include <iostream>
#include <string>

using namespace std;

string proc(string str) {
    char cur = str[0];
    string ans = "";
    ans += cur;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i-1] && i != str.length() -1) {
            continue;
        }
        
        if ((str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') && i != str.length() - 1 ){
            continue;
        }
        cur = str[i];
        ans += cur;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n-1; i++){
        cin >> str;
        cout << proc(str) << " ";
    }
    cin >> str;
    cout << proc(str) << endl;
}