class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // total substrings per string can differ by 1 at most
        // 
        if(s3.size() != s1.size() + s2.size() ){
            return false;
        }

        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        dp[0][0] = true;

        for(int i = 0 ; i <= s1.size(); ++i){
            for(int j = 0; j <= s2.size(); ++j){
                int k = i + j -1;

                if(i > 0 && dp[i-1][j] && s1[i-1] == s3[k]){
                    dp[i][j] = true;
                }

                if( j > 0 && dp[i][j-1] && s2[j-1] == s3[k]){
                    dp[i][j] = true;
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }
};
