class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())return false;
        unordered_map<char,char> m;
        unordered_set<char> se;

        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            auto it = m.find(c);
            auto it1 = m.find(t[i]);
            if(it == m.end() && se.insert(t[i]).second ){// char not found
                m[c] = t[i];

                continue;
            }else{

                if(t[i] != m[c]){
                    return false;
                }
            }

        }
        return true;
    }
};