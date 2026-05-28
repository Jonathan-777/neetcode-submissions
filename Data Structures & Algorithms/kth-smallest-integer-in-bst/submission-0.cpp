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
    int kthSmallest(TreeNode* root, int k) {// since its a binary tree inorder will always work
        helper(root,k);
        return ans;
        
    }

    void helper(TreeNode* root, int& k){
        if(!root){
            return;
        }

        helper( root->left, k);
        
        

        if(root){
            k--;
            if(k == 0){
            ans = root->val;
            }
        }
        helper( root->right, k);
        


    }
};
