class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int result = 0;
        while(l < r){
            int minh = min(heights[l], heights[r]);

            result = max(result, (r - l) * minh);

            if(heights[l] > heights[r]){
                r--;
            } else {
                l++;
            }
        }

        return result;
    }
};
