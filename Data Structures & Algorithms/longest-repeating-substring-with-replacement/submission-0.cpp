class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;// char and freq
        int l = 0; 
        int r = 0;
        int ans=0;

        int maxf = 0;

        for( r = 0 ; r < s.size(); ++r){      
            m[s[r]]++;
            maxf = max(maxf, m[s[r]]);

            while((r - l + 1) - maxf > k){
                m[s[l]]--;

                l++;

            }
            ans = max(ans, r - l + 1);


        }
        return ans;
    }
};
