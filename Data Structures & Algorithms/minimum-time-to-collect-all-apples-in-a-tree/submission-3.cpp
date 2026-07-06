class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int, vector<int>> adj;

        queue<int> q;

        for(const auto& edge : edges){
            int ai = edge[0];
            int bi = edge[1];
            adj[ai].push_back(bi);
            adj[bi].push_back(ai);
        }
        
        for(const auto& [k,v] : adj){
            if(v.size() == 1 && k != 0 && hasApple[k] == false ){
                q.push(k);
            }
        }

        while(!q.empty()){
            int node = (int)q.front();   
            int parent = *adj[node].begin();
            q.pop();

            if(hasApple[node] == true)continue;

            // adj.erase(node); this is how to erase from non sequential containers
            adj.erase(node);

            erase(adj[parent], node);

            if(adj[parent].size() == 1 && parent != 0){
                q.push(parent);
            }
        }

        return max(0, ((int)adj.size() -1) * 2);
    }
};