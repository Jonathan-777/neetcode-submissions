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

        map<int,int> m;
        
        for(const auto& interval : intervals){
            m[interval.start]++;
            m[interval.end]--;
        }

        int ans = 0;
        int working_rooms = 0;

        for(const auto [k,v] : m){
            working_rooms += v;
            ans = max(ans, working_rooms);
        }

        return ans;
    }
};
