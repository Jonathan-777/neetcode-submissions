class Solution {
public:
    int maxProfit(vector<int>& prices) {

        /*/  Buy today-> Earliest you can sell is tomorrow.
        Sell today-> Mandatory cooldown tomorrow -> Earliest you can buy is the day after tomorrow.
        
        
        In DP stock problems, on any given day, you always have two choices: take an action (buy/sell) OR do nothing (rest/hold). 
        */
        int n = prices.size();
        
        int buyTomorrow = 0;
        int sellTomorrow = 0;
        

        int buyDayAfterTomorrow = 0;


        for (int i = n - 1; i >= 0; --i) {
                //left : buy today , right : buy tomorrow (we are looking to the future to calculate, this only works because we have already been to the future in previous iterations)!!!!!
            int buyToday = max(sellTomorrow - prices[i], buyTomorrow);
            

            int sellToday = max(buyDayAfterTomorrow + prices[i], sellTomorrow);
            
            buyDayAfterTomorrow = buyTomorrow;
            buyTomorrow = buyToday;
            sellTomorrow = sellToday;
        }

        return buyTomorrow;
    }
};