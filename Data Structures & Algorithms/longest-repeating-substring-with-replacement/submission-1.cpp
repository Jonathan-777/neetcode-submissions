class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char,int> m;
        int ans = 0;
        int curr_max = 0;

        for( r = 0 ; r < s.size(); ++r){
            m[s[r]]++;
            curr_max = max(curr_max, m[s[r]]);

            while(k < (r - l + 1) - curr_max){
                m[s[l]]--;
                l++;
            }
            ans = max(ans , (r - l + 1));
        }


        return ans;
    }
};
