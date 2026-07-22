class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> s(nums.begin(), nums.end());


        for(int num : s){
            if(s.count(num - 1)){
                continue;
            } else {
                int temp = 1;

                while(s.count(num + 1)){
                    temp += 1;
                    num += 1;
                }

                result = max(result, temp);
            }
        }


        return result;
    }
};
