class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; 
        int r = heights.size()-1;
        int ans = 0; 

        while(l < r){
            int candidate = (r-l) * min(heights[l] , heights[r]);
            if(ans < candidate){
                ans = candidate;
            }
            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }

        }
        return ans;
    }
};
