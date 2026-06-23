class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        // int R = 0;
        // int C = 0;
        int working_C = 0;
        int working_R = 0;

        string t = "&#";
        for(const auto& c : s){
            t += c;
            t += "#";
        }
        t += "!";
        vector<int> dp(t.size(), 0);

        for(int i = 1; i < t.size()-1; ++i){
            // check for shortcut
            // check for palindrome increase

            if(i < working_R && dp[(working_C * 2) - i] != 0){
                dp[i] = min( working_R - i, dp[(working_C * 2) - i]);
            }

            while(i + dp[i] + 1 < t.size() && t[ i + dp[i] + 1] == t[i - dp[i] - 1]){
                dp[i]++;
                
            }

            if( working_R < i + dp[i]){
                working_R = i + dp[i];
                working_C = i;
            }
            ans += (dp[i] + 1) /2;// since our t string is twice the size
        }
        return ans;
    }
};
