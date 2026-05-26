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
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans;
        
    }
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = helper(root->right) ;
        int r = helper(root->left) ;

        if( ans < l + r){
            ans = l + r;
        }

        return max(l,r) + 1;
    }
};
