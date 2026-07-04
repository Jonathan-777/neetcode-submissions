class Solution {
public:
    vector<vector<string>> partition(string s) {// manachers algorithm

        int working_r = 0;
        int working_c = 0;
        string t = "!#";
        
        for(const auto&  c : s){
            t += c;
            t += "#";
        }
        t += "$";
        vector<int> v(t.size(), 0);

        for(int i = 1; i < t.size()-1; ++i){

            if( i < working_r && v[working_c * 2 - i] > 1){
                v[i] = min(working_r - i, v[working_c * 2 - i]);
            }

            while(i + v[i] < t.size() && t[i + 1 + v[i]] == t[i - 1 - v[i]]  ){
                v[i]++;
            }

            if (i + v[i] > working_r) {
                working_c = i;
                working_r = i + v[i];
            }


        }

        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0, s, v, path, ans);
        return ans;


    }

    private:
    void backtrack(int start, const string& s, const vector<int>& v, vector<string>& path, vector<vector<string>>& ans) {
        // Base case: we reached the end of the string, save the current partition
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            // Map substring s[start...end] to its center in transformed string t
            int center_in_t = start + end + 2;
            int len = (end - start) + 1;

            // O(1) palindrome check using Manacher's precomputed radius array v
            if (v[center_in_t] >= len) {
                path.push_back(s.substr(start, len));
                backtrack(end + 1, s, v, path, ans);
                path.pop_back(); // Backtrack to try the next substring
            }
        }
    }
};


