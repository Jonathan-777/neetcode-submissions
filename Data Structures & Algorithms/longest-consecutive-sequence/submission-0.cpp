class Solution {
public:
    int longestConsecutive(vector<int>& nums) {// create hashmap, update the ends of each sequence
        int ans = 0; 
        unordered_map<int,int> m;
        

        for(int i = 0 ; i < nums.size(); ++i){
            if(m[nums[i]] > 0) continue; 
            m[nums[i]] = 1 + (m[nums[i] - 1] + m[nums[i] + 1]);// in case we need to merge 2 growing lists we must add the values of the 2

            
                m[ nums[i]  - m[nums[i] - 1] ] = m[nums[i]];
            
                m[ nums[i]  + m[nums[i] + 1]] = m[nums[i]];
            
            
            if(m[nums[i]] > ans ){
                ans = m[nums[i]];
            }
        }

        return ans;
    }
};
