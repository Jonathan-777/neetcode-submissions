class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        int max_count = 0;
        for(auto c : tasks){
            v[c - 'A']++;
            max_count = max(max_count, v[c - 'A']);
        }

        int counts_max = 0;
        for(int i = 0; i < 26; i++){
            if(v[i] == max_count){
                counts_max++;
            }
        }
        int candidate =  ((max_count - 1) * (n + 1)) + counts_max;
        return max((int)tasks.size(), candidate);
        
    }
};
