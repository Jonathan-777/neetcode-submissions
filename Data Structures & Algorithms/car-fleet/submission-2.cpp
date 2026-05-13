class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0; 
        double curr_time = 0.0;
        vector<pair<int,int>> v;
        int size = position.size();
        for(int i = 0 ; i < size ; ++i){
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        double limit_time = 0.0;

        for(int i = 0 ; i < size; ++i){

            curr_time  = (double)(target - v[i].first) / v[i].second;// curr =  how long till this specific car reaches the goal?

            if(curr_time >  limit_time){
                ans++;
                limit_time = curr_time;
            }
        }
        return ans;
    }
};
