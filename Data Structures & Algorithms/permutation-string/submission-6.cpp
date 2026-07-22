class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())return false;

        vector<int> v1(26,0);
        vector<int> v2(26,0);

        int l = 0;

        for(int i = 0; i < s1.size(); ++i){
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }

        for(int r = s1.size(); r < s2.size(); ++r){
            if(v1 == v2)return true;
            v2[s2[l++] - 'a']--;
            v2[s2[r] - 'a']++;

        }
        return v1 == v2;
    }
};
