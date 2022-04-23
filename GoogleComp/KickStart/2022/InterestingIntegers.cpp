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

#define ll long long

ll sumDigs(ll no) {
    ll s = 0;
    while (no > 0) {
        int rem = no % 10;
        s += rem;
        no /= 10;
    }
    return s;
}

vector<ll> prodSum(ll no) {
    ll prod = 1;
    ll s = 0;
    while (no > 0) {
        int rem = no % 10;
        prod *= rem;
        s += rem;
        no /= 10;
    }
    vector<ll> ans(2, 0);
    ans[0] = (prod);
    ans[1] = (s);
    return ans;
}

long long sol(long long & a, long long & b) {
    long long ans = 0;
    vector<ll> ps = prodSum(a);

    ll sumDig = ps[1];
    ll prodDig = ps[0];
    int lastDig = a % 10;

    if (prodDig % sumDig == 0) {
        ans++;
    }

    for (ll no = a+1; no <= b; no++) {
        if (lastDig == 9 || lastDig == 0) {
            ps = prodSum(a);
            sumDig = ps[1];
            prodDig = ps[0];
        }
        else {
            sumDig += 1;
            prodDig /= lastDig;
            lastDig++;
            prodDig *= lastDig;
        }
        if (prodDig % sumDig == 0) {
            ans++;
        }
    }

    return ans;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
       ll a, b;
       cin >> a >> b;
       ll ans = sol(a, b);

       cout << "Case #" << i+1 << ": " << ans << '\n';
    }
}