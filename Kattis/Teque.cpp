#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>


using namespace std;

class DQueue {
public:
    int size = 0;
    int cap = 0;
    vector<int> store;
    int front = -1;
    int rear = -1;


    DQueue(int n = 10) {
        store = vector<int>(n);
        cap = n;
    }

    bool isFull() {
        return size == cap;
    }

    bool isEmpty() {
        return size == 0;
    }

    void pushFront(int val) {
        if (isFull()) {
            resize(2*cap);
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
            store[front] = val;
            size++;
            return;
        }
        if (front == 0) { front = cap - 1; }
        else { front--; }
        store[front] = val;
        size++;
    }

    void pushBack(int val) {
        if (isFull()) {
            resize(2*cap);
        }
        if (isEmpty()) {
            rear = 0;
            front = 0;
            store[rear] = val;
            size++;
            return;
        }
        if (rear == cap-1) { rear = 0; }
        else { rear++; }
        store[rear]= val;
        size++;
    }

    void print() {
        if (isEmpty()) { return; }
        int index = front;
        while (true) {
            cout << store[index] << " " ;
            if (index == rear) { break; }
            if (index == cap - 1) {index = 0;}
            else {index++;}
        }
        cout << endl;
    }

    void resize(int newCap) {
        if (newCap <= size) { return; }
        vector<int> newStore(newCap);
        int index = front, newIndex = 0;
        while (index >= 0) {
            newStore[newIndex++] = store[index];
            if (index == rear) { break; }
            if (index == cap - 1) { index = 0; }
            else { index++; }
        }
        store = newStore;
        cap = newCap;
        front = 0;
        rear = size-1;
    }

    int getFront() {
        if (size == 0) { return -1; }
        return store[front];
    }

    int getBack() {
        if (size == 0) { return -1; }
        return store[rear];
    }
};

void sol() {
}

int main() {
    DQueue dq;
}