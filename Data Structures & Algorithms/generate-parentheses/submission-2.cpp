class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> v(n + 1);
        v.at(0) = {""};

        for(int i = 1; i <= n ; i++){// mindblown how 20 lines of code can hide complexity under the hood
            for(int j = 0 ; j < i ; ++j){
                for(string inner : v.at(j)){
                    for(string outter : v.at(i - j - 1)){ // the 2 innermost loops add up to our curr n size
                        v[i].push_back( "(" + inner + ")" + outter);
                    }
                }
            }
        }
        return v[v.size()-1];
    }
};
