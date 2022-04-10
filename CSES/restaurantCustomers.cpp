#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>


using namespace std;

struct Person {
    int enter;
    int leave;
    Person(int e, int l) {
        enter = e; leave = l;
    }

    Person() {enter = 0; leave = 0;}

};

struct Event {
    int time;
    int val;
};

struct CompEvent {
    bool operator() (Event& a, Event& b) {
        return a.time > b.time;        
    }
};

bool compEvent(Event& a, Event& b) {
    return a.time > b.time;
}

int sol(priority_queue<Event, vector<Event>, CompEvent>& ev) {
    int maxPeople = 0, curPeople = 0;
    while(!ev.empty()) {
        Event e = ev.top();
        ev.pop();
        // cout << e.time << ' ' << e.val << '\n';
        curPeople += e.val;
        if (curPeople > maxPeople) {
            maxPeople = curPeople;
        }
    }
    return maxPeople;
}

int main() {
    int n;
    cin >> n;
    priority_queue<Event, vector<Event>, CompEvent> ev;
    for (int i = 0; i < n; i++) {
        int enterTime, leaveTime;
        cin >> enterTime >> leaveTime;
        ev.push({enterTime, 1});
        ev.push({leaveTime, -1});
    }
    cout << sol(ev) << '\n';
}