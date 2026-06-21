class Solution {
public:
    int maxScore(string s) {
        // res = Max of all (leftZeros + rightOnes)
        // res = Max of all (leftZeros + (totalOnes - leftOnes))
        // res = totalOnes (constant) + Max of all (leftZeros - leftOnes)

        int zeros = 0, ones = 0, res = INT_MIN;

        if (s[0] == '0') {
            zeros++;
        } else {
            ones++;
        }

        for (int i = 1; i < s.size(); i++) {
            res = max(res, zeros - ones);// this answers the question: 'how can i maximize the zero count on the left while splitting string in 2)
            if (s[i] == '0') {
                zeros++;// if the last item is a zero we are not going to use it in our calculation in the return statment, in case 0's dominate the string
            } else {
                ones++;
            }
        }

        return res + ones;
    }
};