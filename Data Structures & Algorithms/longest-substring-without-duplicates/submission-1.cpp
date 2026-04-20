class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0; 
        int l = 0; 
        int r = 0;
        unordered_map<char,int> m;

        for(r = 0 ; r < s.size(); ++r){
            auto it = m.find(s[r]);
            if(it != m.end()){
              

            // already exists
                l = max(l, m[s[r]] + 1);

                
            }
            m[s[r]] = r;
            ans = max( ans,  r - l + 1);
        } 

        return ans;
    }
};
