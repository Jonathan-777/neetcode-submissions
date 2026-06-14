struct DSU{
    vector<int> group_size;
    vector<int> parent;
    DSU(int n): group_size(n+1,1){
        parent.resize(n +1);
        for(int i = 0 ; i < n ; ++i){
            parent[i] = i;
            
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
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        int N  = grid.size();
        DSU group_path_finder(N * N);
        vector<tuple<int,int,int>> pos;

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                pos.emplace_back(grid[i][j],i,j);
            }
        }
        sort(pos.begin(), pos.end());

        for(auto& [val,i,j] : pos){
            int curr = (i * N) + j;
            for(int z = 0; z < directions.size(); ++z){
                int ROW = directions[z].first + i;
                int COL = directions[z].second + j;
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






/*
3. Better Cache Locality for "Directions"
Last Solution: Used vector<vector<int>> directions. This is a very "heavy" data structure. It allocates one array on the heap for the outer vector, and four separate arrays on the heap for the inner vectors. This causes memory fragmentation and cache misses.

This Solution: Uses vector<pair<int, int>> directions. This allocates exactly one continuous block of memory on the heap. Because the memory is contiguous, the CPU can cache it much more efficiently.
*/


