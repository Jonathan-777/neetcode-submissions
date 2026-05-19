class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 4 cases
        int l = 0; 
        int r = nums.size() -1;
        while(l <= r){
            int middle = (l + r) / 2;
            if(nums[middle] == target){
                return middle;
            }

            if(nums[middle] >= target){
                if(nums[l] <= target || nums[l] > nums[middle]){
                    r = middle -1;
                }else{
                    l = middle+1;
                }
            }else{
                if(nums[r] >= target || nums[r] < nums[middle]){
                    l = middle + 1;
                }else{
                    r = middle -1;
                }
            }
        }
        return -1;
        
    }
};
