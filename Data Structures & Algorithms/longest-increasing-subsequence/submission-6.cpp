class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increasing;

        for(const auto& x : nums){
            auto it = lower_bound(increasing.begin(), increasing.end(), x);

            if(it == increasing.end()){
                increasing.push_back(x);
            }else{
                *it = x;
            }
        }
        return increasing.size();
    }
};
