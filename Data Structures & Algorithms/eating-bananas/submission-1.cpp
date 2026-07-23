class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int result = r;

        while(l <= r){
            int mid = l + (r - l)/2;
            int i = 0;
            long long hours = 0;

            for (int p : piles) {
                hours += ceil(static_cast<double>(p) / mid);
            }
            
            if(hours <= h){
                result = mid;
                r = mid - 1;
            } else if(hours > h){
                l = mid + 1;
            }

        }

        return result;
    }
};
