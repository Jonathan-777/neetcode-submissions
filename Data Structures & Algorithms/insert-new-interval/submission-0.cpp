class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            int prev_end = vec.back()[1];
            int curr_end = intervals[i][1];
            int curr_begin = intervals[i][0];
            if(curr_begin > prev_end ){
                vec.push_back(intervals[i]);
            }else{
                vec.back()[1] = max( prev_end, curr_end);
            }

        }
        return vec;
        
    }
};
