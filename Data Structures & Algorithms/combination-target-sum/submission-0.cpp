class Solution {
public:
    
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int index = 0;
        helper(nums,target,0,{},index);
        return ans;
        
    }

    void helper(vector<int>& nums, int target, int sum, vector<int> working_nums, int curr_index){
        if(sum > target){
            
            return;
        }

        for(int i = curr_index; i < nums.size(); ++i){
            // sum = sum + nums[i];
            
            working_nums.push_back(nums[i]);
            if(sum + nums[i] == target) ans.push_back(working_nums);
            
            helper(nums, target, sum + nums[i], working_nums, i);//cannot reference back from working nums to nums
            working_nums.pop_back();

        }

    }
};
