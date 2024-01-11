#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    TreeNode* right, *left;
    int val;
};


class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> parents;
        return maxAncestorDiff(root, parents);
    }

    int getMaxDiff(int val, vector<int>& parents) {
        int maxDiff = 0;
        int temp = 0;
        for (int p : parents) {
            temp = abs(p - val);
            maxDiff = max(temp, maxDiff);
        }
        return maxDiff;
    }

    int maxAncestorDiff(TreeNode* root, vector<int>& parents) {
        if (root == NULL) { return 0; }
        int maxDiff = getMaxDiff(root->val, parents);
        parents.push_back(root->val);
        maxDiff = max(maxDiff, maxAncestorDiff(root->right, parents));
        maxDiff = max(maxDiff, maxAncestorDiff(root->left, parents));
        parents.pop_back();
        return maxDiff;
    }
};