class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;

        for( int i = 0 ; i < numbers.size(); ++i){
            int need = target - numbers[i];
            auto it = m.find(need);
            if(it != m.end()){
                return {(*it).second, i+1 };
            }
            m[numbers[i]] = i+1;
        }
        
    }
};
