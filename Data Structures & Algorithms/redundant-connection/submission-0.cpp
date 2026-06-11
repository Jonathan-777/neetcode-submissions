class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        queue<int> q;
        vector<int> parent(n+1);
        vector<int> group_count(n+1,0);
        iota(parent.begin(), parent.end(), 0);
        

        auto dsu_helper = [&](this auto& self , int x)->int{
            if(parent[x] != x){
                parent[x] = self(parent[x]);
            }
            return parent[x];
        };
        
        for(int i = 0; i < n ; ++i){
            int up = dsu_helper(edges[i][0]);
            int vp = dsu_helper(edges[i][1]);

            if(up == vp){
                return {edges[i][0],edges[i][1]};
            }
            if(group_count[vp] > group_count[up]){
                swap(vp,up);
            }
            group_count[up] += group_count[vp];
            parent[vp] = up;
            
        }
        return {};
        
    }
};
