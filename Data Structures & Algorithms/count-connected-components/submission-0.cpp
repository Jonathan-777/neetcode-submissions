struct DSU{
    vector<int> parent;
    vector<int> group_count;
    int components_count = INT_MIN;//max/min

    DSU(int n ){
        parent.resize(n);
        group_count.resize(n);
        components_count = n;
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            group_count[i] = 1;
        }
    }

    int find_parent_helper(int n){
        if( parent[n] != n){
           parent[n] = find_parent_helper(parent[n]);
        }
        return parent[n];
    }

    void union_helper(int u, int v){
        int up = find_parent_helper(u);
        int vp = find_parent_helper(v);
        if(parent[vp] == parent[up])return;
        if( parent[vp] > parent[up]){
            swap(up, vp);
        }
        components_count--;
        group_count[up] += group_count[vp];
        parent[vp] = parent[up];

    }
    int components(){
        return components_count;
    }


};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU tree(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            tree.union_helper(u,v);
        }
        return tree.components();

    }
};
