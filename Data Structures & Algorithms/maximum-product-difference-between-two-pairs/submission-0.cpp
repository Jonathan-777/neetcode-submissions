class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int productBig = 0;
        int productSmall= 0;

        auto it = max_element(nums.begin(), nums.end());

        productBig = *it;

        nums.erase(it);
        nums.shrink_to_fit();
        it = max_element(nums.begin(), nums.end());

        productBig *= *it;

        it = min_element(nums.begin(),nums.end());
        productSmall = *it;

        nums.erase(it);

        it = min_element(nums.begin(),nums.end());
        
        productSmall *= *it;

        return (productBig - productSmall);

        
    }
};