#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>


using namespace std;

class TQ {
private:
    deque<int> q1, q2;

    void balanceLeft() {
        int temp = q2.front();
        q2.pop_front();
        q1.push_back(temp);
    }

    void balanceRight() {
        int temp = q1.back();
        q1.pop_back();
        q2.push_front(temp);
    }

    void balance() {
        int diff = q1.size() - q2.size();
        if (diff < 0) {
            for (; diff < 0; diff += 2) {
                balanceLeft();
            }
        } else if (diff > 1) {
            for (; diff > 1; diff -= 2) {
                balanceRight();
            }
        }
    }

public:
    void push_back(int x) {
        q2.push_back(x);
        balance();
    }

    void push_front(int x) {
        q1.push_front(x);
        balance();
    }

    void push_middle(int x) {
        q1.push_back(x);
        balance();
    }

    int get(int i) {
        if (i < q1.size()) {
            return q1[i];
        } else {
            i -= q1.size();
            return q2.at(i);
        }
    }
};

void sol() {
    TQ tq;
    int t;
    cin >> t;
    string op;
    int x;
    for (int i = 0; i < t; i++) {
        cin >> op;
        cin >> x;
        if (op == "push_back") {
            tq.push_back(x);
        } else if (op == "push_front") {
            tq.push_front(x);
        } else if (op == "get") {
            cout << tq.get(x) << "\n";
        } else {
            tq.push_middle(x);
        }
    }
}

int main() {
    sol();
}