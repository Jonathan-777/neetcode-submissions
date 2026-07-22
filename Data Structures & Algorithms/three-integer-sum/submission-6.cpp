class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i+1;
            int k = nums.size() - 1;
            int target = nums[i] * -1;

            while(j < k){
                if(nums[j] + nums[k] == target){
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }

                    while(k > j && nums[k] == nums[k + 1]){
                        k--;
                    }
                } else if(nums[j] + nums[k] < target){
                    j++;
                } else {
                    k--;
                }
            }
        }

        return result;
    }
};
