class Solution {
    // Simple, collision-free encoding for (i, j)
    static size_t encode(int i, int j, int n) {
        return (size_t)i * n + j;
    }

    struct DSU {
        unordered_map<size_t, size_t> parent;
        unordered_map<size_t, int> sz;

        size_t find(size_t x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(size_t a, size_t b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }

        void add(size_t x) {
            if (!parent.count(x)) {
                parent[x] = x;
                sz[x] = 1;
            }
        }
    };

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu;
        const int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        // 1. Add every land cell and union adjacent ones
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                size_t cur = encode(i, j, n);
                dsu.add(cur);

                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 0)
                        continue;
                    size_t nei = encode(ni, nj, n);
                    dsu.add(nei);
                    dsu.unite(cur, nei);
                }
            }
        }

        // 2. Collect the two distinct island roots
        unordered_set<size_t> roots;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    roots.insert(dsu.find(encode(i, j, n)));

        // Guaranteed exactly two by problem statement
        auto it = roots.begin();
        size_t rootA = *it;
        size_t rootB = *next(it);

        // 3. Multi-source BFS from island A
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && dsu.find(encode(i, j, n)) == rootA) {
                    q.emplace(i, j);
                    vis[i][j] = true;
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc])
                        continue;

                    if (grid[nr][nc] == 1) {
                        // Hit land → check if it belongs to the other island
                        if (dsu.find(encode(nr, nc, n)) == rootB)
                            return dist;
                        // same island – just mark visited (should already be)
                        vis[nr][nc] = true;
                    } else {
                        // water
                        vis[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                }
            }
            ++dist;
        }
        return -1; // unreachable
    }
};