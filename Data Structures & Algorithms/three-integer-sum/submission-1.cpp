class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size  = nums.size();
        unordered_map<int,int> m;
        sort(nums.begin(),  nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < size; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            m[nums[i]] = i;
            int R = size-1;
            int L = i+1;
            int target = nums[i] * -1;

            while( L < R){
                if((nums[L] + nums[R]) == target){
                    ans.push_back({nums[L], nums[R], nums[i]});

                    L++;
                    R--;                    
                 while(L < R && nums[L] == nums[L -1]){
                        L++;
                 }
                 while(R > L && nums[R] == nums[R+1] ){
                        R--;
                 }
                }else if((nums[L] + nums[R]) > target){
                    R--;
                }else{
                    L++;
                }



            }

        }
        return ans;
        
    }
};
