class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k - 1;
        vector<int> result;

        while(r < nums.size()){
            int max = *max_element(nums.begin() + l, nums.begin() + r+1);
            result.push_back(max);
            l++;
            r++;
        }

        return result;
    }
};
