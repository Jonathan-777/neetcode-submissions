class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Use unordered_set so we can easily erase edges from both directions in O(1) time
        unordered_map<int, unordered_set<int>> adj;
        
        for(const auto& edge : edges){
            int ai = edge[0];
            int bi = edge[1];
            adj[ai].insert(bi);
            adj[bi].insert(ai);
        }
        
        queue<int> q;
        for(const auto& [k, v] : adj){
            // If it's a leaf, not the root, and has no apple, queue it for pruning
            if(k != 0 && v.size() == 1 && !hasApple[k]){
                q.push(k);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // 1. Identify the single neighbor this leaf is attached to
            int neighbor = *adj[node].begin();
            
            // 2. Erase the leaf from the map completely
            adj.erase(node);
            
            // 3. CRITICAL: Erase the leaf from the neighbor's list too!
            adj[neighbor].erase(node);
            
            // 4. If the neighbor just became a new leaf, isn't the root, and has no apple, queue it
            if(neighbor != 0 && adj[neighbor].size() == 1 && !hasApple[neighbor]){
                q.push(neighbor);
            }
        }
        
        // If only the root (or nothing) is left, time is 0.
        // Otherwise, time is (Remaining Nodes - 1) * 2 seconds.
        return max(0, ((int)adj.size() - 1) * 2);
    }

};