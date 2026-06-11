class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);// instead of keeping all 3 items we drop the source node and keep weight and destination, which is not to be  connfused with pq's  curr_time, curr_node pair
        vector<int> visited(n+1,0);
        int visited_count = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int min_time = INT_MIN;

        

        for(int i = 0; i < times.size(); ++i){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({t,v});

        }
        pq.push({0,k});

        while(!pq.empty()  && visited_count < n){
            auto [time, curr] = pq.top();
            pq.pop();

            if(visited[curr] > 0)continue;//////////
            
            visited[curr]++;
            visited_count++;

            for(int i = 0 ; i < adj[curr].size(); ++i){
                auto [t, d] = adj[curr][i];
                pq.push({t + time , d});
            }
            if(visited_count == n){
                min_time = time;
            }


        }



        return (min_time == INT_MIN) ? -1 : min_time;

    

        
    }
};
