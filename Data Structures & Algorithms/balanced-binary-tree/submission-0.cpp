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
        bool balance = true;
    bool isBalanced(TreeNode* root) {
        helper(root);
        return balance;
        
    }

    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = helper(root->left);
        int r = helper(root->right);

        if(abs(l-r) > 1){
            balance = false;
        }

        return max(l,r) + 1;
    }
};
