class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(nums.begin(), nums.end());
        ans.resize(n*2);

        for(int i = n; i < ( n*2); ++i){
            ans[i] = nums[i - n];
        }
        return ans;
    }
};