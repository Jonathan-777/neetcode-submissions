/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() < 2) return true;
         sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b){
            return a.start < b.start;
         });

        vector<Interval> vec;
        vec.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            int curr_front = intervals[i].start;
            int curr_back = intervals[i].end;
            int prev_back = vec.back().end;
            if(curr_front >= prev_back){
                vec.push_back(intervals[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};
