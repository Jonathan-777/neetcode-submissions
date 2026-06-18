class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

       int n = digits.size();
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            
            // If the digit is less than 9, just add 1 and return. 
            // No carry-over needed.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // If the digit is 9, it becomes 0. 
            // The loop continues to the next digit to carry the 1.
            digits[i] = 0;
        }
        
        // If we make it out of the loop, it means ALL digits were 9s.
        // We need to insert a 1 at the beginning of the array.
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
