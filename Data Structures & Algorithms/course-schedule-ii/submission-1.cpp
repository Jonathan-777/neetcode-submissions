class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        vector<int> visited(numCourses,0);
        queue<int> q;
        vector<int> ans;

        for(auto pre : prerequisites){
            int c = pre[0];
            int dependent = pre[1];
            inDegree[c]++;
            adj[dependent].push_back(c);
        }

        for(int i = 0 ; i < numCourses; ++i){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr] > 0)return {};// if not 0 it will be false
            visited[curr]++;
            ans.push_back(curr);

            for(int i = 0 ; i < adj[curr].size(); ++i){
                inDegree[adj[curr][i]]--;

                if(inDegree[adj[curr][i]] == 0){
                    q.push(adj[curr][i]);
                }
            }


        }

        
        return (ans.size() == numCourses)? ans : vector<int>{};
    }
};
