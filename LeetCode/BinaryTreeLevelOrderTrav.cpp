// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// Uses BFS to navigate the tree, keeps track of level of each node and each node

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> que;
        que.push({0, root});
        vector<vector<int>> ans;
        vector<int>buffer;
        pair<int, TreeNode*> node;
        int curLevel = 0;
        while(!que.empty()) {
            node = que.front();
            que.pop();
            if (node.second == NULL) {
                continue;
            }
            if (curLevel != node.first) {
                ans.push_back(buffer);
                curLevel = node.first;
                buffer.clear();
            }
            buffer.push_back(node.second->val);
            que.push({curLevel+1, node.second->left});
            que.push({curLevel+1, node.second->right});
        }
        if (buffer.size() > 0) {
            ans.push_back(buffer);
        }
        return ans;
    }
};