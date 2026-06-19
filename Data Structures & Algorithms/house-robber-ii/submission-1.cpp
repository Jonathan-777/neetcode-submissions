class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2)return nums[0];
        vector<int> left(nums.begin(), nums.end()-1);
        vector<int> right(nums.begin() +1, nums.end());

        auto rob = [&](vector<int> v){
            int first = 0;
            int second = 0;

            for(auto x : v){
                int temp = max(second, first + x);
                first = second;
                second = temp; 
            }
            return second;
        };

        return max(rob(left), rob(right));
        
    }
};
