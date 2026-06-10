class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        int processed_count = 0;

        for(auto x : prerequisites){
            int c = x[0];
            int dep = x[1];
            
            indegree[c]++;
            adj[dep].push_back(c);

        }

        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int curr = q.front();
            q.pop();
            processed_count++;
            if(processed_count > numCourses)return false;

            for(int i = 0; i < adj[curr].size(); ++i){

                indegree[ adj[curr][i] ]--;
                
                if(indegree[adj[curr][i]] == 0){
                    q.push(adj[curr][i]);

                }

            }
        }

        return processed_count == numCourses;
        
    }
};
