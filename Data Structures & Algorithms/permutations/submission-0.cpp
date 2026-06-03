class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return ans;
        
    }

    void helper(vector<int>& nums, int index){// we never decrease index
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index ; i < nums.size(); ++i){
            swap(nums[index], nums[i]);// wont go out of bounds since we retun at size
            helper(nums,index+1);
            swap(nums[index],nums[i]);

        }
    }
};
