class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {// check for infinite loop (used min price to detect cycles)
        vector<int>min_price(n, INT_MAX);
        queue<tuple<int,int, int>> q; // curr k , working_dist, curr node
        unordered_map<int,vector<pair<int,int>>> adj(n);// original distance, dest_node
        int ans = INT_MAX; // optional variable since we now have min _price

        for(int i = 0; i < flights.size(); ++i){
            int from_i = flights[i][0];
            int to_i = flights[i][1];
            int price_i =flights[i][2];
            adj[from_i].push_back({price_i, to_i});
        }

        min_price[src] = 0;// initialize 
        q.push({0,0,src} ); // curr k , working dist, curr node
        

        while(!q.empty()){
            auto [k_count, price, curr] = q.front();
            q.pop();
            
            

            for(int i = 0 ; i < adj[curr].size(); ++i){
                int temp_price = price + adj[curr][i].first;

                if(min_price[adj[curr][i].second] > temp_price){// cycle check
                    min_price[adj[curr][i].second] = temp_price;
                    q.push({k_count + 1, temp_price , adj[curr][i].second} );
                }
                

                if(k_count <= k && adj[curr][i].second == dst){
                    ans = min(ans, temp_price);
                }
            }

        }

        return (ans == INT_MAX)? -1 : ans;
    }
};
