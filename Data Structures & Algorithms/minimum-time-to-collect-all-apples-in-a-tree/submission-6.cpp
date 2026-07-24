class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        // 0 - n-1

        unordered_map<int, unordered_set<int> > adj;

        //init set
        for(int i = 0; i < n ; ++i){
            adj[i] = unordered_set<int>{};
        }

        for(const auto& v : edges){
            int parent = v[0];
            int child = v[1];

            adj[parent].insert(child);
            adj[child].insert(parent);
        }

        queue<int> q;

        for(const auto& [k,s] : adj){
            if(s.size() == 1 && k != 0 && hasApple[k] == false){
                q.push(k);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(hasApple[curr] == true)continue;

            int parent = *(adj[curr].begin());
            adj[parent].erase(curr);// erase from the parents set
            adj.erase(curr);// erase from the map

            if(adj[parent].size() == 1 && parent != 0 ){
                q.push(parent);
            }

        }

        return ((adj.size()-1) * 2);
        
    }
};