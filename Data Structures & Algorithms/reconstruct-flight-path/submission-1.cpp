class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for(auto ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto & [s,v] : adj){
            sort(v.rbegin(), v.rend());
        }

        vector<string> ans;
        stack<string> s;
        s.push("JFK");
        
        while(!s.empty()){
            string curr = s.top();
            if(adj.find(curr) != adj.end() && !adj[curr].empty()){
                s.push(adj[curr].back());
                adj[curr].pop_back();
            }else{
                ans.push_back(curr);
                s.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
