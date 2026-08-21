class Solution {
public:
    int reverse(int x) {

        bool negative = (x < 0);
        if(negative) x = -x;
        long long new_sum = 0;

        while(x != 0){
            new_sum += (x % 10);
            x /= 10;
            if(x > 0)new_sum *= 10;
            
            
        }

        if(new_sum > (INT_MAX * 1L) + 1)return 0;

        return (negative)? -new_sum : new_sum;
        
    }
};
