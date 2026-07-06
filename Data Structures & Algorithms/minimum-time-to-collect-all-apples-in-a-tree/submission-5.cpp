class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int, vector<int>> adj;

        for(const auto& edge : edges){
            int ai = edge[0];
            int bi = edge[1];
            adj[ai].push_back(bi);
            adj[bi].push_back(ai);
        }
        queue<int> q;

        for(const auto& [k,v] : adj){
            if(v.size() == 1 && k != 0 && hasApple[k] == false){
                q.push(k);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int parent = *adj[curr].begin();
            adj.erase(curr);
            erase(adj[parent], curr);

            if(adj[parent].size() == 1 && hasApple[parent] == false && parent != 0){
                q.push(parent);
            }
        }
        return max(0, ((int)adj.size() -1) * 2);
    }
};