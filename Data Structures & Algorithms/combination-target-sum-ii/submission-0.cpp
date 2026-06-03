class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, {}, 0,0);
        return ans;

        
    }

    void helper(vector<int>& candidates, int target, vector<int> working_arr, int sum, int index){
        if(sum > target)return;

        for(int i = index; i < candidates.size(); ++i){
            if(i > index && candidates[i] == candidates[i-1])continue;
            working_arr.push_back(candidates[i]);
            if(sum + candidates[i] == target)ans.push_back(working_arr);
            helper(candidates, target, working_arr, sum + candidates[i], i + 1);
            working_arr.pop_back();


        }

    }
};
