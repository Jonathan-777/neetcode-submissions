class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size()-1;
        int middle = -1;
        while(l < r){
            middle = (l + r) / 2;
            if(nums[middle] == target)return middle;
            
            if( nums[middle] < target){
                l = middle+1;
            }else{
                r = middle;
            }

        }
        return (nums[l] == target)? l : -1;
    }
};
