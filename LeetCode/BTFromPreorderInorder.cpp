// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// Finds the pattern and uses divide and conquer to solve the problem

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
    TreeNode* buildTree(vector<int>& preorder, int& pi, vector<int>& inorder, int il, int ih) {
        if (pi == preorder.size()) {
            return NULL;
        }
        if (il > ih) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pi]);
        if (il == ih) {
            pi++;
            return root;
        }
        int ri = il;
        for (; ri <= ih; ri++) {
            if (inorder[ri] == preorder[pi]) {
                break;
            }
        }
        pi++;
        root->left = buildTree(preorder, pi, inorder, il, ri-1);
        root->right = buildTree(preorder, pi, inorder, ri+1, ih);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pi = 0;
        return buildTree(preorder, pi, inorder, 0, inorder.size()-1);
    }
};