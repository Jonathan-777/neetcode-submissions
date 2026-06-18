class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            int curr_begin = intervals[i][0];
            int curr_end = intervals[i][1];
            int prev_end = vec.back()[1];
            if( prev_end <= curr_begin){
                vec.push_back(intervals[i]);
            }else{
                ans++;
                vec.back()[1] = min(curr_end, prev_end);
            }

        }
        return intervals.size() - vec.size();
    }
};
