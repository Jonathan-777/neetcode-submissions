class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int index = 0;
        int max_len = 0;

        vector<pair<int,int>> dp(nums.size(), pair<int,int>({0,-1}));

        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] % nums[j] == 0 && dp[i].first < dp[j].first+1){
                    dp[i].first = dp[j].first +1;
                    dp[i].second  = j;
                }

                if(max_len < dp[i].first){
                    index  =i;
                    max_len = dp[i].first;
                }
            }
        }

        vector<int> ans;
        while(index != -1){
            ans.push_back(nums[index]);
            index = dp[index].second;
        }
        return ans;
        
    }
};