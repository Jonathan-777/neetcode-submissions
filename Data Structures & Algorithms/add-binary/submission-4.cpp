class Solution {
public:
    string addBinary(string a, string b) {
        unsigned long long A = 0;
        unsigned long long B = 0;
        int temp = 0;

        for(int i = a.size() - 1; i >= 0; --i) {
            if(a[i] == '1') { 
                // 1ULL means "1 as an Unsigned Long Long"
                A += (1ULL << temp); 
            }
            temp++;
        }
        
        temp = 0;

        for(int i = b.size() - 1; i >= 0; --i) {
            if(b[i] == '1') {
                B += (1ULL << temp);
            }
            temp++;
        }
        
        unsigned long long number = A + B;
        
        if (number == 0) return "0";

        string ans = "";
        int k = 0;
        
        // Loop while the k-th bit of 1 is less than or equal to the number
        // We use an absolute limit of 63 to prevent shifting beyond 64 bits
        while(k < 64 && (1ULL << k) <= number) {
            if((number & (1ULL << k)) != 0) {
                ans += '1';
            } else {
                ans += '0';
            }
            k++; 
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};