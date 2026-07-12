class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({nums[0], nums[0] * -1});

        for(int i = 1; i < nums.size(); ++i){
            int num = nums[i];
            queue<pair<int,int>> new_q;
            while(!q.empty()){
                auto [working_1, working_2] = q.front();
                q.pop();
                int working_1_temp = num +     working_1;
                int working_1_tem = num * -1 + working_1;
                int working_2_temp = num +     working_2;
                int working_2_tem = num * -1 + working_2;


                new_q.push({working_2_temp, working_2_tem});
                new_q.push({working_1_temp, working_1_tem});
            }
            q = new_q;

        }

        while(!q.empty()){// since we must use all 3 numbers to add up to target, we can only check for ans equality at the last queue cycle
            auto [final_1, final_2] = q.front();
            q.pop();
            
            if(final_1 == target){
                ans++;
            }
            if(final_2 == target){
                ans++;
            }
        }
        return ans;
    }
};
