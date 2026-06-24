class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int working_max = nums[0];
        int working_min = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            int num = nums[i];

            if( num < 0){
                swap(working_min, working_max);
            }

            working_max = max( working_max * num, num);
            working_min = min(num, working_min * num);

            ans = max(ans , working_max);
        }
        return ans;
        
    }
};
