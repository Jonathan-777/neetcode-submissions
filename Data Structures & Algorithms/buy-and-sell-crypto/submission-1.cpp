class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = INT_MAX;
        int ans = 0;

        for(int i = 0; i < prices.size(); ++i){
            cheapest = min(cheapest, prices[i]);

            ans = max( ans , prices[i] - cheapest);
        }
        return ans;
    }
};
