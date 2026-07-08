class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> v;

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int curr = nums[i];
            int l = i + 1;
            int r = nums.size()-1;

            while(l < r){
                if(nums[l] + nums[r] == (curr * -1)){
                    v.push_back({nums[l], nums[r], curr});
                    l++;// must increment before the next check.
                    r--;

                    while(r > l && nums[l] == nums[l-1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r+1]){
                        r--;
                    }
                }else if( nums[l] + nums[r] > (curr * -1) ){
                    r--;
                }else{
                    l++;
                }
            }
            
        }
        return v;
        
    }
};
