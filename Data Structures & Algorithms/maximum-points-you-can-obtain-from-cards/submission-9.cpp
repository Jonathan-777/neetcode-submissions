class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int left_sum = 0; 
        int right_sum = 0;
        int ans = 0;

        for(int i = 0; i < k ; ++i){
            left_sum += cardPoints[i];
        }
        ans = left_sum;
        
        int r = cardPoints.size()-1;

        for(int i = k-1; i >= 0 ; --i){
            left_sum -= cardPoints[i];
            right_sum += cardPoints[r];
            r--;

            ans = max(ans, left_sum + right_sum);

        }
        return ans;   
    }
};