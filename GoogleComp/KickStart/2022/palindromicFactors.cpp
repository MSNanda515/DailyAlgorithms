#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>

using namespace std;

vector<long> findFactors(long num) {
    vector<long> fact;
    long sqNum = sqrt(num);
    for (long i = 0; i <= sqNum; i++) {
        if (num % i == 0) {
            fact.push_back(i);
            if (num / i != i) {
                fact.push_back(num / i);
            }
        }
    }
    return fact;
}

bool isPalind(long num) {
    string str = to_string(num);
    int strLen = str.size();
    for (int i = 0; i < strLen / 2; i++) {
        if (str[i] != str[strLen - i - 1]) {
            return false;
        }
    }
    return true;
}

long sol(long num) {
    vector<long> fact = findFactors(num);
    long factPalind = 0;
    for (int i = 0; i < fact.size(); i++) {
        if (isPalind(fact[i])) {
            factPalind++;
        }
    }
    return factPalind;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long num;
        cin >> num;
        cout << "Case #" << i+1 << ": " << sol(num) << '\n';
    }
}