class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        stack<int> s;
        int ans = 0;

        for(int i= 0 ; i < size; ++i){

            while(!s.empty() && (height[i] > height[s.top()])){
                int curr = s.top();
                s.pop();
                if(s.empty())continue;
                int len = min(height[i] , height[s.top()]) - height[curr];

                ans += len * (i - s.top()-1);
                               

            }
            s.push(i);
        }
        return ans;
    }
};
