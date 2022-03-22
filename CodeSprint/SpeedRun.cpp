#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct item {
    int total, start, end;
    bool operator<(const item& r) const {
        return total < r.total;
    }
    bool operator>(const item& r) const {
        return total > r.total;
    }
};

bool operator<(item& l, item& r) {
    return l.total < r.total;
}

int main() {
    priority_queue<item, vector<item> , greater<item> > heap;
    int n, g;
    cin >> g >> n;
    int start, end;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        item ent;
        ent.total = start + end;
        ent.start = start;
        ent.end = end;
        heap.push(ent);
    }
    int task = 0, curTime = 0;
    while(heap.size() > 0) {
        item i = heap.top();
        heap.pop(); 
        if (curTime > i.start) {
            continue;
        }
        task++;
        curTime = i.end;
        if (task == g) {
            break;
        }
    }
    if (task == g) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}