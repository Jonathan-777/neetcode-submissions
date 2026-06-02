class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};

        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            int curr_size = ans.size();
            
            
            for(int z = 0; z < curr_size; z++){
                vector<int> combined = ans[z];
                combined.push_back(num);
                ans.push_back(combined);
            }
            

        }


        return ans;
    }
};
