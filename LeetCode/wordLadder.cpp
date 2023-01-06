// https://leetcode.com/problems/word-ladder/description/
// First makes a graph from the words such that any two words that differ by one char share an edge
// Then uses BFS to find the shortest path in the given graph

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    bool diffByOne(string& w1, string& w2) {
        int diff = 0;
        if (w1.size() != w2.size()) {
            return false;
        }
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                diff += 1;
                if (diff > 1) {
                    return false;
                }
            }
        }
        if (diff == 1) {
            return true;
        }
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int, vector<int>> g;
        bool foundEndWord = false;
        for (int i = 0; i < wordList.size(); i++) {
            g[i];
            if (wordList[i] == endWord) {
                foundEndWord = true;
            }
        }
        if (!foundEndWord) {
            return 0;
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (diffByOne(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }



        vector<int> vis (wordList.size(), -1);
        // vector<int> par (wordList.size(), -1);
        queue<int> que;
        for (int i = 0; i < wordList.size(); i++) {
            if (diffByOne(beginWord, wordList[i])) {
                que.push(i);
                vis[i] = 1;
                // par[i] = -1;
                // cout << " " << wordList[i];
            }
        }
        // cout << endl;
        while (que.size() > 0) {
            int top = que.front();
            que.pop();
            if (wordList[top] == endWord) {
                // for (int i = top; i != -1; i = par[i]) {
                //     cout << " " << wordList[i];
                // }
                return vis[top] + 1;
            }
            int nextLev = vis[top] + 1;
            for (auto it = g[top].begin(); it != g[top].end(); it++) {
                if (vis[*it] > -1) {
                    continue;
                }
                que.push(*it);
                vis[*it] = nextLev;
                // par[*it] = top;
            }
        }
        return 0;
    }
};