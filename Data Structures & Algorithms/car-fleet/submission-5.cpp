class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        double curr_time = 0.0;
        double total_time = 0.0;
        int ans = 0;

        vector<pair<int,int>> v;

        for(int i  = 0; i < position.size(); ++i){
            v.push_back({position[i], speed[i]});
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i < position.size(); ++i){

            curr_time = ((target - v[i].first ) / (double)(v[i].second)) ;

            if(curr_time > total_time){

                ans++;
                total_time = curr_time;
            }

        }
        return ans;
    }
};
