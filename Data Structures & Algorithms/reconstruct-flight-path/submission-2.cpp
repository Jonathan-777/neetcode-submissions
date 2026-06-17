class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        stack<string> s;
        unordered_map<string, vector<string>> adj;
        vector<string> ans;

        for(int i = 0; i < tickets.size(); ++i){
            adj[tickets[i][0]].emplace_back(tickets[i][1]);
        }

        for(auto& [k,v] : adj){
            sort(v.rbegin(), v.rend());
        }
        s.push("JFK");

        while(!s.empty()){
            string curr = s.top();

            if(!adj[curr].empty()){
                string temp = adj[curr].back();
                adj[curr].pop_back();
                s.push(temp);
            }else{
                ans.emplace_back(curr);
                s.pop();
            }
        }
         reverse(ans.begin(), ans.end());
         return ans;
    }
};
