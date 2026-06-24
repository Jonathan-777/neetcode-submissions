class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        
        for(const auto& word : words){
            vector<int> temp(26,0);
            for(auto c : word){

                temp[c - 'a']++;
                // v[c - 'a'] = min(v[c - 'a'], temp[c - 'a']);
            }

            for (int i = 0; i < 26; ++i) {
                v[i] = min(v[i], temp[i]);
            }
            
        }

        vector<string> ans;

        for(int i = 0 ; i < 26; ++i){
            while(v[i] > 0){
                string temp = "" ;
                temp += i + 'a' ;

                ans.push_back(temp);
                v[i]--;

            }
        }
        return ans;
    }
};