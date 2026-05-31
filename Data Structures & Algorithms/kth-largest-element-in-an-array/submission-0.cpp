class Solution {// maxheap or quickselect
public:
    int findKthLargest(vector<int>& nums, int k) {

        nth_element(nums.begin(), nums.rbegin().base() - k , nums.end());
        return nums[nums.size() - k];
    }
};
