class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        auto climb = [&](auto& self, int x){
            if(x == n){
                return 1;
            }
            if( x > n){
                return 0;
            }

            if(memo[x] != -1) return memo[x];

            int one = self(self, x +1);
            int two = self(self, x + 2);

            memo[x] = one + two;
            return memo[x];
        };
        return climb(climb, 0);
        
    }
};
