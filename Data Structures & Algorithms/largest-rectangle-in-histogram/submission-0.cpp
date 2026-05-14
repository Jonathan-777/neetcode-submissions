class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int size = heights.size();
        stack<int> s;


        //monotonic stack
        for(int i = 0; i <= size; ++i){
            while(!s.empty() && ((i == size) || (heights[s.top()] >= heights[i]))){
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() -1;
                ans = max(ans , h * w);
            }
            s.push(i);
        }

        return ans;
        
    }
};
