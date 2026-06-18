class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int l = 0; 
        int ans  = nums[0];
        int reset = nums[0];

        for(int r = 1; r < nums.size(); ++r){
            if(nums[l] < nums[r]){
                reset += nums[r];
            }else{
                reset  = nums[r];
            }
             l = r;
            
            ans = max(ans, reset);
        }
        return ans;
    }
};