class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        int r = s.size()-1;
        unordered_set<int> se;
        int ans = 0;

        for( r = 0; r < s.size(); ++r){
            auto it = se.find(s[r]);

            while(se.find(s[r]) != se.end()){
                se.erase(s[l]);
                l++;

            }

            se.insert(s[r]);
            ans = max(ans , r - l + 1);
        }
        return ans;
    }
};
