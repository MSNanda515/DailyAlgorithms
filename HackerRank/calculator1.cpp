#include <iostream>
#include <vector>

using namespace std;


/*
 * Complete the 'calculate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool isDig(char ch) {
    return (ch >= '0' && ch <= '9');
}

int cal(vector<int>& opd, vector<char>& sign) {
    int ans;
    char oldSign = sign.back();
    sign.pop_back();
    int op1 = opd.back(); opd.pop_back();
    int op2 = opd.back(); opd.pop_back();
    if (oldSign == '+') {
        int ans = op1 + op2;
        opd.push_back(ans);
    }
    else {
        int ans = op2 - op1;
        opd.push_back(ans);
    }
    return ans;
}

int calculate(string s) {
    vector<int> opd;
    vector<char> sign;
    int op = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isDig(s[i])) {
            int dig = s[i] - '0';
            op = op * 10;
        }
        else {
            opd.push_back(op);
            op = 0;
            if (sign.size() == 0) {
                sign.push_back(s[i]);
            }
            else {
                if (s[i] == '(') {
                    sign.push_back(s[i]);
                }
                else if (s[i] == ')') {
                    while(sign.back() != '(') {
                        cal(opd, sign);
                    }
                    sign.pop_back();
                }
            }
        }
    }
    return opd.back();
}

int main()
{
    string s;
    getline(cin, s);

    int result = calculate(s);

    cout << result << "\n";

    return 0;
}
