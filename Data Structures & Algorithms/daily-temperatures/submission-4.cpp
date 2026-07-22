class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> stk;

        
        for(int i = n - 1; i >= 0; i--){
            if(stk.empty()){
                stk.push({temperatures[i], i});
                continue;
            }

            while(!stk.empty() && stk.top().first <= temperatures[i]){
                stk.pop();
            }
            
            if(!stk.empty()){
                result[i] = stk.top().second - i;
            }

            stk.push({temperatures[i], i});   

        }

        return result;
    }
};
