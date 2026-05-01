class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {// must solve using stack, 
    stack<pair<int,int>> s;
    vector<int> ans(temperatures.size(), 0);

        for( int i = temperatures.size() -1; i >=0; i--){
            if(s.empty()){
                s.push({temperatures[i], i});
                continue;
            }
            while(!s.empty() && temperatures[i] >= s.top().first){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top().second - i;
            }
            s.push({temperatures[i], i});

        }
        return ans;
    }
};
