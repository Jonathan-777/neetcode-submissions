class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int l = 0; 
        int r = 0;
        int ans  = nums[0];
        int reset = nums[0];
        auto it = nums.begin();
        auto it_begin = nums.begin()+1;
        while(it != nums.end() && it_begin != nums.end() && *it >= *it_begin){
            ans = max(ans, *it);
            it++;
            it_begin++;
        }
        if(it == nums.end() || it_begin == nums.end())return max(ans, nums.back());
        l = distance(nums.begin(), it);
        r = distance(nums.begin(), it_begin);
        reset = nums[l];
        ans = max(ans,reset);
        

        for( r = r; r < nums.size(); ++r){
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