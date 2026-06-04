class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> v(n+1);
        v[0] = {""};

        for(int i = 1 ; i <= n; ++i){
            for(int j = 0; j < i; j++){


                for(string inner : v[j] ){
                    for(string outter : v[i - j - 1]){
                        v[i].push_back("(" + inner + ")" + outter) ;

                    }
                }
            }
        }
        return v[v.size()-1];
    }
};
