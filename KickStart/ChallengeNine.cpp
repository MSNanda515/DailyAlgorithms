#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>

using namespace std;

using namespace std;

int convDig(char& d) {
    return d - '0';
}

string convChar(int& d) {
    return to_string(d);
}

string sol(vector<int>& dig) {
    long long sum = 0;
    for (int i = 0; i < dig.size(); i++) {
        sum += dig[i];
    }
    long long q1 = floor(sum / 9);
    int rem = 9ll * (q1 + 1) - sum;
    int pos = dig.size();
    for (int i = dig.size() - 1; i >= 0; i--) {
        if (dig[i] <= rem) {
            pos = i;
            break;
        }
    }

    if (rem == 9) {
        rem = 0;
        pos = 0;
    }

    string ans = "";
    for (int i = 0; i < dig.size(); i++) {
        ans += convChar(dig[i]);
        if (i == pos) {
            ans += convChar(rem);
        }
    }
    if (pos == dig.size()) {
        ans = "" + convChar(rem) + ans;
    }
    return ans;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
       string no;
       cin >> no;
       vector<int> dig (no.size(), 0);
       for (int i = 0; i < no.size(); i++) {
           dig[i] = convDig(no[i]);
       }
       string ans = sol(dig);

       cout << "Case #" << i+1 << ": " << ans << '\n';


    }
}