class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            int curr_front = intervals[i][0];
            int prev_back = ans.back()[1];
            int curr_back = intervals[i][1];
            if(curr_front > prev_back){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(prev_back, curr_back);
            }
        }
        return ans;
    }
};
