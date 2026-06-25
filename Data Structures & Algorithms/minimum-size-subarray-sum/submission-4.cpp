class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 1)return 1;
        int l = 0;
        int r = 0;
        int working_sum = 0;
        int ans = INT_MAX;

        for(r = 0; r <nums.size(); ++r){
            working_sum += nums[r];

            while( working_sum >= target){
                ans = min(ans, (r  - l) + 1 );
                working_sum -= nums[l];
                l++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};