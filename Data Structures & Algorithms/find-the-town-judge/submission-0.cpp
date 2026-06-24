
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adjacency;// where bi points to ai

        for(int i = 1; i <= n; i++) {
            indegree[i] = 0;
        }

        for(vector<int> v : trust) {
            indegree[v[0]]++;
            adjacency[v[1]].push_back(v[0]);
        }

        for(auto [k,v] : indegree) {
            if(v == 0) {
                if(adjacency[k].size() == n-1) {
                    return k;
                }
            }
        }

        return -1;
    }
};