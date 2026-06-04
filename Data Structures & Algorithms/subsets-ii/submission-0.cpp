class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        ranges::sort(nums); 

        auto dfs = [&](auto& self, int start) -> void {
            ans.push_back(path);
            for (int i = start; i < nums.size(); ++i) {
                // Skip duplicates at the same depth of the recursion tree
                if (i > start && nums[i] == nums[i - 1]) continue;// skips duplicates
                
                path.push_back(nums[i]);
                self(self, i + 1);
                path.pop_back();
            }
        };
        
        dfs(dfs, 0);
        return ans;
    }
};