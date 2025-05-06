/*
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:

Input: root = [1], target = 1, k = 3
Output: []
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> hasParent; // {node, parent}

    void getParents(TreeNode* node, TreeNode* prev) {
        if (!node) return;
        hasParent[node] = prev;

        getParents(node->left, node);
        getParents(node->right, node);
    }
    void dfs(TreeNode* node, int k, int depth, vector<int>& res, unordered_set<int>& visited) {
        if (!node) return;
        if (visited.find(node->val) != visited.end()) return;
        if (depth == k) res.push_back(node->val);
        visited.insert(node->val);

        dfs(hasParent[node], k, depth + 1, res, visited);
        dfs(node->left, k, depth + 1, res, visited);
        dfs(node->right, k, depth + 1, res, visited);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // get parents of each node
        TreeNode* prev = nullptr;
        getParents(root, prev);

        // run dfs on the graph
        vector<int> res;
        unordered_set<int> visited;
        int depth = 0;

        dfs(target, k, depth, res, visited);

        return res;
    }
};
