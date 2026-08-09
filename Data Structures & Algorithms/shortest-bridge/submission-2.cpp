template<typename T1, typename T2>
size_t hash_f(const pair<T1,T2>& p) {
    size_t h1 = hash<T1>{}(p.first);
    size_t h2 = hash<T2>{}(p.second);
    return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
}

struct DSU {
    unordered_map<size_t, size_t> parent;
    unordered_map<size_t, int> groups;

    void add(size_t x) {
        if (!parent.count(x)) {
            parent[x] = x;
            groups[x] = 1;
        }
    }

    size_t find_parent(size_t u) {
        if (parent[u] != u)
            parent[u] = find_parent(parent[u]);
        return parent[u];
    }

    size_t union_nodes(size_t u, size_t v) {
        size_t up = find_parent(u);
        size_t vp = find_parent(v);
        if (up == vp) return up;

        if (groups[up] < groups[vp])
            swap(up, vp);

        groups[up] += groups[vp];
        parent[vp] = up;
        return up;
    }
};

class Solution {
public:
    vector<pair<int,int>> offsets = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu;

        // 1. Only land cells go into the DSU + union adjacent land
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                size_t cur = hash_f(make_pair(i, j));
                dsu.add(cur);

                for (auto [di, dj] : offsets) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 0)
                        continue;

                    size_t nei = hash_f(make_pair(ni, nj));
                    dsu.add(nei);
                    dsu.union_nodes(cur, nei);
                }
            }
        }

        // 2. Collect the two final roots
        unordered_set<size_t> roots;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    roots.insert(dsu.find_parent(hash_f(make_pair(i, j))));

        auto it = roots.begin();
        size_t parent_A = *it;
        size_t parent_B = *next(it);

        // 3. Multi-source BFS from island A (same idea you already had)
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 &&
                    dsu.find_parent(hash_f(make_pair(i, j))) == parent_A) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        int bridge_length = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();

                for (auto [dr, dc] : offsets) {
                    int ROW = r + dr, COL = c + dc;
                    if (ROW < 0 || COL < 0 || ROW >= n || COL >= n || visited[ROW][COL])
                        continue;

                    if (grid[ROW][COL] == 1) {
                        if (dsu.find_parent(hash_f(make_pair(ROW, COL))) == parent_B)
                            return bridge_length;
                        // same island – just mark
                        visited[ROW][COL] = true;
                    } else {
                        visited[ROW][COL] = true;
                        q.emplace(ROW, COL);
                    }
                }
            }
            ++bridge_length;
        }
        return -1;
    }
};