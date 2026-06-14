class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) : Parent(n + 1), Size(n + 1, 1) {// maps 2d matrix to 1d arr
        for (int i = 0; i <= n; i++) Parent[i] = i;
    }

    int find(int node) {
        if (Parent[node] != node)
            Parent[node] = find(Parent[node]);
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        DSU dsu(N * N);
        vector<tuple<int, int, int>> positions;

        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                positions.emplace_back(grid[r][c], r, c);// value, row , column

        sort(positions.begin(), positions.end());// sort items based on cell value / land height displacement

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        for (auto& [height, r, c] : positions) {
            for (auto& [dr, dc] : directions) {

                int ROW = r + dr, COL = c + dc;

                if (ROW >= 0 && ROW < N && COL >= 0 && COL < N && grid[ROW][COL] <= height) {
                    dsu.unionSets(r * N + c, ROW * N + COL);
                }
            }
            if (dsu.connected(0, N * N - 1)) { // if the last item in our 2d arr at grid[N-1][N-1] and grid[0][0] are in the same group then we have a valid path, return that path...
                cout << "hello";
                return height;
            }
        }
        return N * N;
    }
};













