class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {// monotonic stack

        stack<int> s;
        int ans = 0;

        for(int i = 0; i <= heights.size(); ++i){

            while( !s.empty() && (i == heights.size() ||  heights[i] < heights[s.top()]) ){
                int tall = s.top();
                s.pop();

                int w = (s.empty()) ? i : i - s.top() - 1;
                int h = heights[tall];

                ans = max(ans, h * w);

            }

            s.push(i);
        }
        return ans;
    }
};
