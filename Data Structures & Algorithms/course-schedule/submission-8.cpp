class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adjacency;
        int count = 0;

        for(int i = 0; i < numCourses; i++){
            indegree[i] = 0;
        }
        

        for(vector<int> v : prerequisites) {
            indegree[v[1]]++;
            adjacency[v[0]].push_back(v[1]);
        }


        queue<int> q;

        for(auto [k,v] : indegree) {
            if(v == 0) {
                q.push(k);
            }
        }

        while(!q.empty()) {
            int key = q.front();
            q.pop();
            count++;
            if(count > numCourses) return false;

            auto temp = adjacency[key];

            for(int x : temp) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        return count == numCourses;
    }
};
