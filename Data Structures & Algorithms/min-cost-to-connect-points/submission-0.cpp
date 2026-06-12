class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        int connected_points = 0;
        vector<bool> visited(n, false);
        
        // Min-heap storing {distance, node_index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Start at point 0 with a distance of 0
        pq.push({0, 0});
        
        while (connected_points < n) {
            auto [dist, curr] = pq.top();
            pq.pop();
            
            // If we've already connected this point, skip it
            if (visited[curr]) continue;
            
            // Lock it in
            visited[curr] = true;
            ans += dist;
            connected_points++;
            
            // Throw ALL possible connections from this point into the heap
            for (int next = 0; next < n; ++next) {
                if (!visited[next]) {
                    int manhattan = abs(points[curr][0] - points[next][0]) + abs(points[curr][1] - points[next][1]);
                    pq.push({manhattan, next});
                }
            }
        }
        return ans;
    }
};