class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int, unordered_set<int> > adj;// if we use a vector lookup will be slower

        for(int i  = 0; i < n; i++){
            adj[i] = unordered_set<int>{};
        }

        for(const auto& edge : edges){
            int parent_node = edge[0];
            int child_node = edge[1];

            adj[parent_node].insert(child_node);
            adj[child_node].insert(parent_node);

        }

        queue<int> q;

        for(const auto& [k,v] : adj){
            if(v.size() == 1 && k != 0 && hasApple[k] == false){
                q.push(k);
            }
        }

        while(!q.empty()){
            int curr_node = q.front();
            q.pop();

            if(hasApple[curr_node] == true)continue;

            int parent_node = *adj[curr_node].begin();

            adj.erase(curr_node);  //erase the leaf node since it does not have an apple

            adj[parent_node].erase(curr_node);  // erase from parent's indegree/outdegree

            if(adj[parent_node].size() == 1 && parent_node != 0 && hasApple[parent_node] == false){
                q.push(parent_node);
            }         
            

        }

        return (adj.size() * 2)-2;
        
    }
};