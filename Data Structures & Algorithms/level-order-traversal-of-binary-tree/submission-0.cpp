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
        TreeNode* node = root;
        queue<TreeNode*> q;
        if(node)q.push(node);
        vector<vector<int>> v;

        while(!q.empty()){
            vector<int> temp_v;
            int size = q.size();

            for(int i = 0; i < size ; ++i){
                temp_v.push_back(q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            v.push_back(temp_v);
        }
        return v;
        
    }
};
