class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int l = 0 ; 
        int r = 0;
        vector<int> ans;

        for( int r = k; r <= nums.size(); ++r){
            int temp = *max_element(nums.begin()+ l, nums.begin() + r);
            ans.push_back(temp);
            l++;
        }
        return ans;
    }
};
