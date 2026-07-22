class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;

        for(int i = 0; i < height.size(); i++){
            int lMax = height[i];
            int rMax = height[i];

            for(int j = 0; j < i; j++){
                lMax = max(lMax, height[j]);
            }

            for(int j = i+1; j < height.size(); j++){
                rMax = max(rMax, height[j]);
            }

            int minH = min(lMax, rMax);

            result += minH - height[i];
        }

        return result;
    }
};
