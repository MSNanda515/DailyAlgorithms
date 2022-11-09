// https://leetcode.com/problems/roman-to-integer/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rom = {
            {'I', 1}, {'V', 5}, {'X',10}, {'L', 50}, {'C', 100}, {'D', 500}, 
            {'M', 1000}
        };
        int ans = 0, dig = 0;
        for (int i = 0; i < s.size(); i++) {
            dig = 0;
            if (i < s.size() - 1 && rom[s[i]] < rom[s[i+1]]) {
                dig = rom[s[i+1]] - rom[s[i]];
                i++;
            } else {
                dig += rom[s[i]];
            }
            ans += dig;
        }
        return ans;
    }
};