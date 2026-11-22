class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int, unordered_set<int>> adj;

        for(int i = 0; i < n; ++i){
            adj[i] = unordered_set<int>{};
        }

        for(const auto& edge : edges){
           int  n1 = edge[0];
            int n2 = edge[1];

            adj[n1].insert(n2);
            adj[n2].insert(n1);
        }
        
        queue<int> q;

        for(const auto& [i,v] : adj){
            if(v.size() == 1 && i != 0 && hasApple[i] == false){
                q.push(i);
            }
        }

        while(!q.empty()){
            int leaf = q.front();
            q.pop();

            if(hasApple[leaf] == true )continue;

            int parent = *adj[leaf].begin();

            adj[parent].erase(adj[parent].find(leaf));

            adj.erase(leaf);

            if(parent != 0 && adj[parent].size() == 1){
                q.push(parent);
            }
        }

        return (adj.size() * 2) -2;
    }
};