struct DSU{
    vector<int> group_size;
    vector<int> parent;
    DSU(int n){
        group_size.resize(n*n);
        parent.resize(n*n);
        for(int i = 0 ; i < n*n ; ++i){
            parent[i] = i;
            group_size[i] = 1;            
        }
    }

    int parent_find(int curr){
        if(parent[curr] != curr){
            parent[curr] = parent_find( parent[curr]);
        }
        return parent[curr];
    }

    void union_groups(int u, int v){
        int up = parent_find(u);
        int vp = parent_find(v);
        if(up == vp)return;
        if(group_size[vp] > group_size[up]){
            swap(up, vp);
        }

        parent[vp] = parent[up];
        group_size[up] += group_size[vp];
        
    }

    bool same_parent(int u, int v){
        return parent_find(u) == parent_find(v);
    }

};

class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        int N  = grid.size();
        DSU group_path_finder(N * N);
        vector<tuple<int,int,int>> pos;

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                pos.push_back({grid[i][j],i,j});
            }
        }
        sort(pos.begin(), pos.end());

        for(auto [val,i,j] : pos){
            int curr = (i * N) + j;
            for(int z = 0; z < directions.size(); ++z){
                int ROW = directions[z][0] + i;
                int COL = directions[z][1] + j;
                if(ROW < 0 || COL < 0 || ROW >= N || COL >= N || grid[ROW][COL] > grid[i][j])continue;
                int lower_water = (ROW * N) + COL;

                group_path_finder.union_groups(curr, lower_water);
                
            }
            if(group_path_finder.same_parent(0,(N*N)-1)){
                return val;
            }
        }

        return -1;
        
    }
};










