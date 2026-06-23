class Solution {
public:
    string longestPalindrome(string s) {

        int center = 0; 
        int C = 0;
        int R = 0;
        int working_R=0;
        int biggest_len = 0;
        string t = "$#";

        for(auto& c : s ){
            t += c;
            t += "#";
        }

        t += "!";
        vector<int> dp(t.size(),0);

        for(int i = 1; i < t.size() - 1; ++i){
            // check for shortcut
            // check for updating working rightmost

            if(i <= working_R && dp[center * 2 - i] > 0){
                dp[i] = min( working_R - i, dp[center * 2 - i] );
            }

            while(i + dp[i] + 1 < t.size() &&  t[i + dp[i] + 1] == t[i - dp[i] - 1]){
                dp[i]++;
            }

            if( (i + dp[i]) > working_R){
                working_R = i + dp[i];
                center = i;
            }
            // update biggest center
            // update biggest palindrome right boundary

            if( (dp[i] * 2) + 1 > biggest_len){
                biggest_len = (dp[i] * 2) + 1;
                R = i + dp[i];
                C = i;
            }
        }

        int start = (C - dp[C]) / 2;
        return s.substr(start, (biggest_len /2));
        
    }
};
