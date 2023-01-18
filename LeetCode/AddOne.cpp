// https://leetcode.com/problems/plus-one/description/
// Uses the concept of full adder, carry propogates over

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    void addOne(vector<int>& digits, int add, int car, int pos) {
        if (pos < 0) {
            digits.insert(digits.begin(), add);
            return;
        }
        int newSum = digits[pos] + add + car;
        int newDig = newSum % 10;
        int newCar = newSum / 10;
        digits[pos] = newDig;
        if (newCar > 0) {
            addOne(digits, newCar, 0, pos-1);
        }
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        addOne(digits, 1, 0, digits.size()-1);
        return digits;
    }
};
