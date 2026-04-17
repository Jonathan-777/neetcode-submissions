class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copyS = strs;
        vector<vector<string>> ans;
        int size = strs.size();

        for(auto &x : copyS){
            sort(x.begin(), x.end());
        }

        for(int i =  0 ; i < copyS.size() ; i++){
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j = copyS.size() -1; j > i; j--){
                
                if(copyS[i] == copyS[j]){
                    temp.push_back(strs[j]);
                    copyS.erase(copyS.begin()+j);
                    strs.erase(strs.begin()+j);
                }
            }
            ans.push_back(temp);

        }


        return ans;
    }
};
