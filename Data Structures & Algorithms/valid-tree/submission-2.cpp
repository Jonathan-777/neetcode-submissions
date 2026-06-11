struct DSU{
    vector<int> parent;
    vector<int> node_count;
    int group_count = INT_MAX;

    DSU(int n ){
        group_count = n;
        parent.resize(n+1);
        node_count.resize(n+1);

        for(int i = 0 ;i < n ; ++i){
            parent[i]  = i;
            node_count[i] = 1;
        }

    }

    int find_group_representative( int node){
        if(parent[node] != node){
            parent[node] = find_group_representative(parent[node]);
        }

        return parent[node];                
    }

    bool union_helper(int u, int v){
        int up = find_group_representative(u);
        int vp = find_group_representative(v);
        if(parent[up] == parent[vp])return false;

        if(node_count[vp] > node_count[up]){
            swap(vp,up);
        }
        group_count--;
        node_count[up] += node_count[vp];
        parent[vp] = parent[up];
        return true;


    }

    int total_groups(){
        return group_count;
    }

};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU tree(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(!tree.union_helper(u,v)){
                return false;
            }
        }

        return (tree.total_groups() == 1) ? true : false;

    }
};
