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
    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return max(ans.first, ans.second);
    }

    pair<int,int> helper(TreeNode* root){
        if(!root){
            return {0,0};
        }

        pair<int,int> l_house = helper(root->left);
        pair<int,int> r_house = helper(root->right);

        int curr_house = root->val + l_house.second + r_house.second;

        int skip_house = max(l_house.first, l_house.second) + max(r_house.first,r_house.second);
        return {curr_house, skip_house};

    }
};