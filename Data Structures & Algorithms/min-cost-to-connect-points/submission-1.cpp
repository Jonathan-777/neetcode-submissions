class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {// doing this algorithm without visited is not worth
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;// 
        int size = points.size();
        vector<int> visited(size, 0);
        int ans = 0;
        
        pq.push({0,0});

        while(!pq.empty()){
            auto [dist, curr] = pq.top();
            pq.pop();
            if(visited[curr] != 0) continue;
            visited[curr]++;
            ans += dist;


            for(int i = 0; i < size; ++i){
                if(visited[i] > 0)continue;
                int x = points[curr][0];
                int y = points[curr][1];
                
                int xTwo = points[i][0];
                int yTwo = points[i][1];

                int manhattan = abs(x - xTwo) + abs(y - yTwo);

                pq.push({ manhattan, i});

            }
            
            
        }


     return ans;
    }
};
