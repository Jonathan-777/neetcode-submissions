class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;
        
        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            

            if (curr < 0) {// since max_so_far will result in a smaller negative number when multiplied by a negative number we swap it for min_so_far which will give us a bigger negative number
                swap(max_so_far, min_so_far);
            }
            
            
            max_so_far = max(curr, max_so_far * curr);
            min_so_far = min(curr, min_so_far * curr);// if we get a negative number hold on to that in case we need it later, if we never see a negative number min_so_far has no use
            cout << min_so_far;
            result = max(result, max_so_far);
        }
        
        return result;
    }
};