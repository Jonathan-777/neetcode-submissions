class Solution {
public:
    int specialArray(vector<int>& nums) {
        int r = nums.size();
        int l = 0;
        sort(nums.begin(), nums.end());


        while(l <= r) {
            int mid = l + (r - l) / 2;
            int tempCount = 0;

            // for(int x : nums) {
            //     if(x >= mid) {
            //         tempCount++;
            //     }
            // }
            
            tempCount = count_if(nums.begin(), nums.end(), [&](const int& n){
                return n >= mid;
            });

            if(mid == tempCount) {
                return tempCount;
            } else if(mid >= tempCount) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }




        return -1;
    }
};