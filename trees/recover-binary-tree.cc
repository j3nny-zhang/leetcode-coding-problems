/**
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
**/

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
class Solution {
    // need tp pass addresses of prev, first, and last because they are being modified in the recursion
    void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &last) {
        if (!root) return;
        inorder(root->left, prev, first, last);

        // process
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                last = root;
            } else { // first is already set
                last = root;
            }
        }
        prev = root;
        inorder(root->right, prev, first, last);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *last = nullptr;
        inorder(root, prev, first, last);
        swap(first->val, last->val);
    }
};
