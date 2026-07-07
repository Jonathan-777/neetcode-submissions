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
    vector<int>  pq;

    TreeNode* convertBST(TreeNode* root) {
        populate_pq(root);
        sort(pq.begin(), pq.end());

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int temp = 0;

            int curr = q.front()->val;

            auto it = find(pq.begin(), pq.end(), curr);
            
            while(it != pq.end()){
                temp += *it;
                it = next(it);
            }
            q.front()->val = temp;
            if(q.front()->right)q.push(q.front()->right);
            if(q.front()->left)q.push(q.front()->left);
            q.pop();
        }


        return root;
    }

    void populate_pq(TreeNode* root){
        if(!root){
            return;
        }
        pq.push_back(root->val);
        populate_pq(root->left);
        populate_pq(root->right);

    }
};