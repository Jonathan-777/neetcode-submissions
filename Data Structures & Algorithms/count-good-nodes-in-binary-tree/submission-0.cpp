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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        helper(root,INT_MIN);
        return ans;
        
    }
    void helper(TreeNode* root, int curr_max){
        if(!root){
            return;
        }
        if(curr_max <= root->val)ans++;
        int cm = max(root->val, curr_max);
        helper(root->right, cm);
        helper(root->left, cm);

    }
};
