class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2)return nums[0];
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        
        return max(helper(v1), helper(v2));
        
    }

    int helper(vector<int>& v){
        int first = 0; 
        int second = 0;

        for(int i =0; i < v.size(); ++i){
            int temp = max( second, first + v[i]);
            first = second;
            second = temp;
        }
        return second;
    }
};
