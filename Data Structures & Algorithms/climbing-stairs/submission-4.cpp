class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n + 1, 0);
        
        auto climb = [&](auto& self, int x){
            if( x == n){
                return 1;
            }
            if( x > n){
                return 0;
            }

            if(dp[x] != 0){
                return dp[x];
            }


            int one = self(self, x + 1);
            int two = self(self, x + 2);
            dp[x] = one + two;
            return dp[x];
        };

        return climb(climb, 0);
    }
};
