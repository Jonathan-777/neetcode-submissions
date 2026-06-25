class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        while (!nums.empty() && k > 1) {
            auto it = max_element(nums.begin(), nums.end());
            nums.erase(it); 
            k--; // Decrement k to prevent infinite loops
        }
        return *max_element(nums.begin(), nums.end());
    }
};