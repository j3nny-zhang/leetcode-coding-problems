/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
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

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<vector<int>> result;

        if (!root) return result;
        bfs.push(root);

        TreeNode* curr;

        while (!bfs.empty()) {

            vector<int> children;
            int size = bfs.size();
            while (size > 0) {
                curr = bfs.front();
                bfs.pop();
                children.push_back(curr->val);
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
                size -= 1;
            }
            result.push_back(children);
            
        }

        return result;
    }
};

// a dfs solution found on leetcode:
class Solution {
public:
    void dfs(TreeNode * root ,vector<vector<int>>&ans,int d=0){
      if(!root)return;
      if(d>=ans.size())ans.push_back({});
      ans[d].push_back(root->val);
      dfs(root->left,ans,d+1);
      dfs(root->right,ans,d+1);
  }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
         if(!root)return ans;
         dfs(root,ans);
        return ans;
    }
};
