// https://leetcode.com/problems/validate-binary-search-tree/description/
// Uses DFS to traverse the tree and verify if each subtree is valid

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>

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
    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};