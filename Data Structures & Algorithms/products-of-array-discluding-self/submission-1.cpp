class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftproduct(nums.size(), 1);
        vector<int> rightproduct(nums.size(), 1);

        int lp = 1;
        int rp = 1;

        for(int i = 1; i < nums.size(); i++){
            lp *= nums[i-1];
            leftproduct[i] = lp;
        }

        for(int i = nums.size() - 2; i >= 0; i--){
            rp *= nums[i+1];
            rightproduct[i] = rp * leftproduct[i];
        }

        rightproduct.back() = leftproduct.back();

        return rightproduct;

    }
};
