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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        auto inorder = [&](auto& self, TreeNode* root){
            if(!root){
                return;
            }
            self(self, root->left);
            ans.push_back(root->val);
            self(self,root->right);
            return;
        };

        inorder(inorder,root);
        return ans;
    }
};