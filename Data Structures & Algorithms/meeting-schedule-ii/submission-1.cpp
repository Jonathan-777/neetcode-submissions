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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)return 0;

        vector<int> end_interval;
        vector<int> begin_interval;
        int ans = 0;
        int working_ans = 0;

        for(auto meeting : intervals){
            end_interval.push_back(meeting.end);
            begin_interval.push_back(meeting.start);
        }

        sort(begin_interval.begin(), begin_interval.end());
        sort(end_interval.begin(), end_interval.end());
        int end_interval_count = 0;

        for( int i = 0; i < begin_interval.size(); ++i){

            if(begin_interval[i] < end_interval[end_interval_count]){// we cannot update end_interval_count here since we still need to check for conflicts with other rooms untill all conflicts with curr end_interval_count index are resolved
                ans++;
            }else{
                end_interval_count++;
            }

        }
        return ans;
    }
};
