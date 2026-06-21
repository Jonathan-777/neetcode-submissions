class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n,0);

        auto climb = [&](auto& self, int i)->int{
            if(i == n){
                return 1;
            }
            if(i > n){
                return 0;
            }

            if(dp[i] != 0){
                return dp[i];
            }

            int one = self(self, i+1);
            int two = self(self, i + 2);
            
            dp[i] = one + two;
            return dp[i];
        };
        return climb(climb, 0);

        
    }
};
