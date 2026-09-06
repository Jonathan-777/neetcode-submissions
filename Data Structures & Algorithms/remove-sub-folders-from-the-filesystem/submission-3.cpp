#include <iterator>

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s;
        sort(folder.begin(), folder.end());

        for(const auto file : folder){
            bool flag = false;
            istringstream ss(file);
            string token = "";
            string curr_word = "";
            while(getline(ss, token, '/')){
                if(token.empty()){
                    continue;
                }

                curr_word += "/";
                curr_word += token;

                if(s.find(curr_word) != s.end()){
                    flag = true;
                }



            }

            if(!flag){
                s.insert(curr_word);
            }
        }

        vector<string> ans(make_move_iterator(s.begin()) ,  make_move_iterator(s.end()));
        

        return ans;
        
    }
};