class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;// number, count

        for(const auto& num : nums){
            m[num]++;
        }
        int ans = 0;

        for(auto [k,v] : m){
           if(v == 1){
            return -1;
           }

           ans += (2 + v) / 3;
        }
        return ans;
    }
};