/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.
*/


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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int l, int r, int& index, unordered_map<int, int> &m) {
        if ((index >= inorder.size()) || (l > r)) return nullptr;

        TreeNode* newNode = new TreeNode(preorder[index]);
        int pos = m[preorder[index]];
        index += 1;

        newNode->left = buildTreeHelper(preorder, inorder, l, pos-1, index, m);
        newNode->right = buildTreeHelper(preorder, inorder, pos+1, r, index, m);

        return newNode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // put index and values of preorder into a map
        unordered_map<int, int> m; // {value, index}
        for (int i = 0; i < preorder.size(); i++) {
            m[inorder[i]] = i;
        }
        int index = 0;
        return buildTreeHelper(preorder, inorder, 0, inorder.size()-1, index, m);
    }
};
