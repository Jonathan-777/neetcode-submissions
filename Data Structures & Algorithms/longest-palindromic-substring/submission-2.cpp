class Solution {
public:
    string longestPalindrome(string s) {// Mananchers Algorithm

        int rightmost_index = 0;
        int working_C = 0;
        int center = 0;
        int working_length = 0;
        string t = "^#";
            for(int i = 0; i < s.size(); ++i){
                t += s[i];
                t += "#";
            }
            t += "$";
        vector<int> dp(t.size(), 0);

        for(int i = 1; i < t.size(); ++i){// must start at index 1 since index 0 cannot be a palindrome and to avoid going out of bounds (mistake 1)
            // check if we can skip iterations
            if(i < rightmost_index && dp[working_C * 2 - i] > 0){
                dp[i] = min(rightmost_index - i, dp[working_C * 2 - i]);
            }

            // check for palindrome expansion
            while((i + dp[i] + 1) < t.size() && t[i + dp[i] + 1] == t[i - dp[i] - 1]){  // stay in bounds by properly using -1 and +1 depending on the direction we are moving (mistake 2)
                dp[i]++;
            }

            // check for new working rightmost palindrome
            if(rightmost_index < dp[i] + i){
                rightmost_index = dp[i] + i;
                working_C = i;
            }
           

            // check for overall greatest palindrome
            if(((dp[i] * 2) + 1) > working_length){
                working_length = (dp[i] * 2) + 1;
                center = i;
            }
        }
        cout << dp[center];
        int start_index = ((center - dp[center]) ) / 2;
        working_length = working_length / 2;
        return s.substr(start_index, working_length );

    }
};
