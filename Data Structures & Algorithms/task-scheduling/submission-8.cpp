class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        int max_count = 0;

        for(const auto& task : tasks){
            v[task - 'A']++;
            max_count = max(max_count, v[task - 'A']);
        }
            int same_len = 0;
        for(int i = 0; i < 26; ++i){

            if(v[i] == max_count){
                same_len++;
            }
        }
        int temp =  (max_count - 1)* (n + 1) + (same_len );
        return max(temp, (int)tasks.size());
    }
};
