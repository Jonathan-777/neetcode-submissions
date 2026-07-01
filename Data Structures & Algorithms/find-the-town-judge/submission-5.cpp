

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {// khans algorithm

        unordered_map<int, unordered_set<int>> adj;
        vector<int> indegree(n+1, 0);

        for(auto&  v : trust){
            int ai = v[0];
            int bi = v[1];
            adj[bi].insert(ai);// reverse adj
            indegree[ai]++;
        }

        queue<int> q;

        for(int i = 1; i <= n; ++i){
            int x = indegree[i];
            if(x == 0){
                q.push(i);
            }
        }


        int ans = -1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(adj[curr].size() == n-1){
                ans = curr;
            }
        }

        return ans;
        
    }
};