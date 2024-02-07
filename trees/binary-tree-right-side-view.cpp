// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

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

public:
    vector<int> rightSideView(TreeNode* root) {
        // breadth first
        vector<int> result;
        if (!root) return {};

        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int size = bfs.size();
            vector<int> children;
            while (size-- > 0) {
                TreeNode *curr = bfs.front();
                bfs.pop();
                children.push_back(curr->val);
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
            }

            int childrenSize = children.size();
            result.push_back(children[childrenSize - 1]);
        }
        return result;
    }
};
