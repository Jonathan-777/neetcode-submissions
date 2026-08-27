#include <vector>
#include <utility>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        // Base cases
        if (n == 1) return {0};
        if (n == 2) return {0, 1};

        // Graph representations
        std::vector<std::vector<int>> adj(n);
        std::vector<int> degree(n, 0);

        // Build adjacency list and degree array
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Initialize the first layer of leaves
        std::vector<int> leaves;
        leaves.reserve(n); // Pre-allocate to prevent reallocations
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push_back(i);
            }
        }

        // Peel the onion until 2 or fewer nodes remain
        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            remaining_nodes -= leaves.size();
            
            std::vector<int> new_leaves;
            new_leaves.reserve(remaining_nodes); // Memory optimization

            // Process current leaves and find the next layer
            for (int leaf : leaves) {
                for (int neighbor : adj[leaf]) {
                    // "Remove" the edge by decrementing the neighbor's degree
                    if (--degree[neighbor] == 1) {
                        new_leaves.push_back(neighbor);
                    }
                }
            }
            
            // Fast swap to the new layer using move semantics
            leaves = std::move(new_leaves);
        }

        return leaves;
    }
};