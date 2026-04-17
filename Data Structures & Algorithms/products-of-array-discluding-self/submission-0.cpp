class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> forward(size,1);
        vector<int> backward(size,1);

        forward[0] = nums[0];
        backward[size-1] = nums[size-1];
        vector<int> ans(size,1);

        for(int i = 1; i < size; i++){
            forward[i] = nums[i] * forward[i-1];
        }

        for(int i = size-2; i >= 0; i--){
            backward[i] = nums[i] * backward[i+1];
        }

        for(int i = 0 ; i < size; i++){
            if(i == 0){
                ans[i] = backward[i+1];

            }else if( i == size-1){
                ans[i] = forward[i-1];

            }else{
                ans[i] = forward[i-1] * backward[i+1];

            }
        }
        return ans;

    }
};
