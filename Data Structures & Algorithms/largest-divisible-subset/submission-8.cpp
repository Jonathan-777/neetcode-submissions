class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // dp[i] = {maxLen, prevIdx}

        int maxLen = 1, startIndex = 0;

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            dp[i][1] = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j][0] + 1 > dp[i][0]) {// j is the smaller item so , this is always valid. the second statement filters out subsets
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }

            if (dp[i][0] > maxLen) {
                maxLen = dp[i][0];
                startIndex = i;
            }
        }

        vector<int> subset;
        while (startIndex != -1) {
            subset.push_back(nums[startIndex]);
            startIndex = dp[startIndex][1];
        }
        return subset;
    }
};