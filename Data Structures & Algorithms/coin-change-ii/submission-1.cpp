class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i] represents the number of ways to make the amount 'i'
        vector<unsigned int> dp(amount + 1, 0);
        
        // Base case: There is 1 way to make the amount 0 (use no coins)
        dp[0] = 1;
        
        // Iterate through each coin one by one
        for (int coin : coins) {
            // Update the dp array for all amounts that are >= the current coin
            for (int i = coin; i <= amount; i++) {// the idea is that in this range we calculate the #'s cleanly divisible by our i and that will give us the future counts that we need
                dp[i] += dp[i - coin];
            }
            
        }

        return dp[amount];
    }
};