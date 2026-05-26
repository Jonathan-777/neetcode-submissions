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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int l = maxDepth(root->right) + 1;
        int r = maxDepth(root->left) + 1;

        // if(ans < l || ans < r){
        //     int candidate = max(l,r);
        //     ans = max(ans, candidate);
        // }
        return max(l,r);
    }
};
