#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        // 1. Find the two smallest (puts them at index 0 and 1)
        // O(N) average time
        std::ranges::nth_element(nums, nums.begin() + 1);
        int minProduct = nums[0] * nums[1];

        // 2. Find the two largest (puts them at the end)
        // O(N) average time
        std::ranges::nth_element(nums, nums.end() - 2);
        int maxProduct = nums[nums.size() - 1] * nums[nums.size() - 2];

        return maxProduct - minProduct;
    }
};