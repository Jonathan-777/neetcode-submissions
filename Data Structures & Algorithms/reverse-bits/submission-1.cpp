class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t strictly_reverse = 0;

        for(int i = 0; i < 32; ++i){

            strictly_reverse <<= 1;

            strictly_reverse |= (n & 1);

            n >>= 1;
        }

        return strictly_reverse;
    }
};
