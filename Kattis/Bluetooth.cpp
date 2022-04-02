#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printVector(vector<int> v) {
    for (auto c : v) {
        cout << c << ' ';
    }
    cout << endl;
}

int sol(unordered_map<string, char>& prob) {
    vector<int> upper (16, 0);
    vector<int> lower (16, 0);
    for (auto it = prob.begin(); it != prob.end(); it++) {
        if (it->first.find('+') >= 0) {
            // upper jap
            if (it->first[0] == '+') {
                if (it->second == 'm')
                    upper[7+ it->first[1]-'0'] = 1;
                else
                    upper[7+ it->first[1]-'0'] = 2;
            }
            else {
                if (it->second == 'm')
                    upper[8 - (it->first[0]-'0')] = 1;
                else
                    upper[8 - (it->first[0]-'0')] = 2;
            }
        }
        else {
             // lower jap
            if (it->first[0] == '-') {
                if (it->second == 'm')
                    lower[7+ it->first[1]-'0'] = 1;
                else
                    lower[7+ it->first[1]-'0'] = 2;           
            }
            else {
                if (it->second == 'm')
                    lower[8 - (it->first[0]-'0')] = 1;
                else
                    lower[8 - (it->first[0]-'0')] = 2;
            }
        }
    }

    // printVector(upper);
    // printVector(lower);

    int side = 0, left = 0, right = 0;
    for (int i = 0; i < 8; i++) {
        if (upper[i] == 2 || lower[i] == 2) {
            side = -1;
            break;
        }

        if (upper[i] == 0 && lower[i] == 0) {
            left++;
        }
    }
    if (side != -1 && left > 0) {
        return 1;
    }

    side = 0;
    for (int i = 8; i < 16; i++) {
        if (upper[i] == 2 || lower[i] == 2) {
            side = -1;
            break;
        }

        if (upper[i] == 0 && lower[i] == 0) {
            right++;
        }
    }
    if (side != -1 && right > 0) {
        return 0;
    }
    return 2;
}

int main() {
    int t;
    cin >> t;
    unordered_map<string, char> prob;
    for (int i = 0; i < t; i++) {
        string tooth; char p;
        cin >> tooth >> p;
        prob[tooth] = p;
    }
    cout << sol(prob) << endl;
}