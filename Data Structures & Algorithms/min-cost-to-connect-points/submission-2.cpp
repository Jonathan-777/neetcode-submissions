class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {//prims minimum spanning tree algorithm
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;// dist, node
        vector<int> visited(points.size(), 0);
        int ans = 0;
        int visited_nodes = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            if(visited[node]++ > 0)continue;
            if(visited_nodes == points.size())return ans;
                ans += dist;
            visited_nodes++;

            for(int i = 0; i < points.size(); ++i){
                    if(visited[i] > 0)continue;
                    int manhattan = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({manhattan, i});

            }
        }
        return ans;
        
    }
};
