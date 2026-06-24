class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int need = 1;

        while(n > 0){
            if(n >= need){
                ans++;
                n -= need;
                need++;
            }else{
                break;
            }
        }
        return ans;
    }
};