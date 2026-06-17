struct DSU{
    vector<int> parent;
    vector<int> group_counts;
    DSU(int N) : group_counts(N,1){
        parent.resize(N);
        for(int i = 0; i < N; ++i){
            parent[i] = i;
        }
    }

    int find_parent(int u){
        if(parent[u] != u){
            parent[u] = find_parent(parent[u]);
        }
        return parent[u];
    }

    void union_helper(int u , int v){
        int up = find_parent(u);
        int vp = find_parent(v);
        if(up == vp)return;
        if(group_counts[vp] > group_counts[up]){
            swap(up, vp);
        }
        parent[vp] = up;
        group_counts[up] += group_counts[vp];
    }
    bool compare_parent(int u, int v){
        return (find_parent(u) == find_parent(v));
    }

};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        DSU dsu(N*N);
        vector<tuple<int,int,int>> v;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        for(int i = 0; i < N; ++i){
            for(int j = 0 ; j < N; ++j){
                v.emplace_back(grid[i][j],i,j);
            }
        }
        sort(v.begin(),  v.end());
 

        for(auto [ val, r, c] : v){

            for(auto [x, y] : directions){
                int ROW = r + x;
                int COL = c + y;
                if(ROW < 0 || COL < 0 || ROW >= N || COL >= N || grid[r][c] < grid[ROW][COL])continue;
                dsu.union_helper((r * N) + c, (ROW * N )+ COL ); // this turns out 2d matrix into 1d arr

            }
            if(dsu.compare_parent(0, (N*N) -1))return val;
        }


       return -1;
        
    }
};
