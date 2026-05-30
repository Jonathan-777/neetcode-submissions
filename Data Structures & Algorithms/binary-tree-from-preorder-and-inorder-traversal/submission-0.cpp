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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {// explore edge
        // we're done recursing through the list of nodes we need to create, set the leaf nodes bottoms to nullptr children
        if(preorder.empty()) return nullptr;

        // create the current node
        TreeNode* root = new TreeNode(preorder[0]);
        
        // find where the new node exists in inorder as an index
        auto idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin(); 

        // create the new left preorder list
        vector<int> left_Preorder(preorder.begin() + 1, preorder.begin() + idx + 1);

        // create the new right preorder list
        vector<int> right_Preorder(preorder.begin() + idx + 1, preorder.end());// [)

        // create the new left inorder list
        vector<int> left_Inorder(inorder.begin(), inorder.begin() + idx);
        
        // create the new right inorder list
        vector<int> right_Inorder(inorder.begin() + idx + 1, inorder.end());

        // recursively build the left tree
        root->left = buildTree(left_Preorder, left_Inorder);

        // recursively build the right tree
        root->right = buildTree(right_Preorder, right_Inorder);

        // return the node we built
        return root;
    }
};