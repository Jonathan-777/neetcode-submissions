class Solution {
public:
    int maxScore(string s) {
        int zeros = 0;
        int ones = 0;
        int balancer = INT_MIN;// cannot start at 0 since any negative numbers will be rendered useless

        if(s[0] == '0'){
            zeros++;
        }else{
            ones++;
        }

        for(int i = 1; i < s.size(); ++i){
            balancer = max(balancer, zeros - ones);
            if(s[i] == '0'){
                zeros++;
            }else{
                ones++;
            }
        }
        return ones + balancer;
    }
};