class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0; 
        int r = nums.size()-1;

        while(l <= r){
            int middle = (l + ((r - l) ) / 2);

            if(nums[middle] == target){
                return  middle;
            }

            if( target <= nums[middle]){

                if(target >= nums[l] || nums[middle] < nums[l]){//the second param only works if there is no duplicates
                    r = middle -1;
                }else{
                    l = middle+1;
                }

            }else{
                if(target <= nums[r] || nums[middle] > nums[r]){
                    l = middle+1;
                }else{
                    r = middle-1;
                }
            }


        }
        return -1;
    }
};
