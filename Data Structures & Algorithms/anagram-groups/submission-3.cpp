class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(string& s : strs){
            string key = "";
            vector<int> freq(26, 0);
            for(char& c : s){
                freq[c - 'a']++;
            }

            for(int i = 0; i < 26; i++){
                key += '#' + to_string(freq[i]);
            }

            m[key].push_back(s);
        }

        vector<vector<string>> result;

        for(auto& [key, val] : m){
            result.push_back(val);
        }

        return result;
    }
};
