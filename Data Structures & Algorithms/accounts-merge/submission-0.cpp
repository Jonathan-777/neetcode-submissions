// dsu solution

struct DSU{

    vector<int> parent;
    vector<int> group_count;
    DSU(int x):group_count(x,1){
        parent.resize(x);
        for(int i = 0; i < x; ++i){
            parent[i] = i;
        }
    }

    int find_parent(int v){
        if(v != parent[v]){
            parent[v] = find_parent(parent[v]);
        }
        return parent[v];
    }

    void union_groups(int u, int v){
        int up = find_parent(u);
        int vp = find_parent(v);
        if(up == vp)return;
        if(group_count[vp] > group_count[up]){
            swap(up,vp);
        }
        group_count[up] += group_count[vp];
        parent[vp] = up;
        return;
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> m; //  email, index names
        DSU dsu(accounts.size());

        for(int i = 0; i < accounts.size(); ++i){
            int curr_name = i;
            for(int j = 1; j < accounts[i].size(); ++j){
                string curr_email = accounts[i][j];

                if(m.find(curr_email) != m.end()){
                    dsu.union_groups(m[curr_email], curr_name);// they are now part of the same group in dsu, so we dont need to keep track of that outside dsu
                }else{
                    m[curr_email] = curr_name;
                }
            }
        }

        unordered_map<int, vector<string>> row_holder; // index, emails
        for(auto [k,v] : m){
            row_holder[dsu.find_parent(v)].push_back(k);
        }

        vector<vector<string>> ans;

        for(auto [k,v] : row_holder){
            string name = accounts[k][0];
            sort(v.begin(), v.end());
            vector<string> temp;
            temp.push_back(name);
            temp.insert(temp.end(), v.begin(),v.end());// when using insert we can dictate the starting index of where we are inserting and then fill the rest
            ans.push_back(temp);
        }
        return ans;



        
    }
};














