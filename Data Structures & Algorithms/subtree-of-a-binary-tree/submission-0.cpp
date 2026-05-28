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

class Solution { // z -- algorithm
public:
    string serialize(TreeNode* root){
        if(!root){
            return "$";
        }

        return "#" + to_string(root->val) + "#" + serialize(root->left) + "#" + serialize(root->right);
    }

    vector<int> z_algorithm(string combined){
        vector<int> v(combined.size(),0);
        int l = 0;
        int r =0;
        for(int i = 1 ; i < combined.size(); i++){
            if(r > i){
                v[i] = min(r - i, v[i - l]);
            }
            while(i + v[i] < combined.size() &&  ( combined[v[i]] == combined[i + v[i]])){
                v[i]++;
            }
            if(r < i + v[i]){
                l = i;
                r = i + v[i];
            }
        }
        return v;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string sr = serialize(subRoot);
        string combined = (sr + "/" + serialize(root));

        vector<int> v = z_algorithm(combined);

        for(int i = sr.size(); i < combined.size(); ++i){
            if(v[i] == sr.size()){
                return true;
            }
        }

        return false;
    }
    
};
