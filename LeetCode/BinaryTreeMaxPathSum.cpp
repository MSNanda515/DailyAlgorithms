
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int traverseTree(TreeNode* root, int& maxVal) {
        if (root == NULL) {
            return 0;
        }
        int chLeft = max(traverseTree(root->left, maxVal), 0);
        int chRight = max(traverseTree(root->right, maxVal), 0);
        maxVal = max(maxVal, chLeft + chRight + root->val);
        return max(chLeft, chRight) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        traverseTree(root, maxVal);
        return maxVal;
    }
};