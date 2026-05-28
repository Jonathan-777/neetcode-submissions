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
    
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN);
    }

    bool helper(TreeNode* root, int maxv, int minv){
        if(!root){
            return true;
        }

        if(root->val <= minv || root->val >= maxv){
            return false;
        }

        bool l = helper(root->left, min(maxv,root->val) ,   minv);

        bool r = helper(root->right,maxv,                  max(minv, root->val));

        return (l && r);


    }
};
