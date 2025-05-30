/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
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
    void helper(TreeNode* root, int& totalSum, string sum) {
        if (!root) return;

        sum += to_string(root->val);

        if (!root->left && !root->right) {
            totalSum += stoi(sum);
        }

        helper(root->left, totalSum, sum);
        helper(root->right, totalSum, sum);

    }
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        string sum = "";
        helper(root, totalSum, sum);
        return totalSum;
    }
};


// LEETCODE'S SOLN
class Solution {
public:
    void preorder(TreeNode* r, int currNumber, int& rootToLeaf) {
        if (r != NULL) {
            currNumber = currNumber * 10 + r->val;
            // if it's a leaf, update root-to-leaf sum
            if (r->left == NULL && r->right == NULL) rootToLeaf += currNumber;
            preorder(r->left, currNumber, rootToLeaf);
            preorder(r->right, currNumber, rootToLeaf);
        }
    }
    int sumNumbers(TreeNode* root) {
        int rootToLeaf = 0;
        preorder(root, 0, rootToLeaf);
        return rootToLeaf;
    }
};
