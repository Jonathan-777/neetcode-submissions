class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;

        // Step 1: Transform the string (e.g., "aba" -> "^#a#b#a#$")
        string T = "^#";
        for (char c : s) {
            T += c;
            T += '#';
        }
        T += "$";

        int n = T.length();
        vector<int> P(n, 0);
        int C = 0; // Center of the rightmost palindrome
        int R = 0; // Right boundary
        int total_palindromes = 0;

        // Step 2: Run Manacher's Algorithm
        for (int i = 1; i < n - 1; ++i) {
            // Mirror property
            if (i < R) {
                int mirror = 2 * C - i;
                P[i] = min(R - i, P[mirror]);
            }

            // Expand around center i
            while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
                P[i]++;
            }

            // Update center and right boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            // Step 3: Calculate total palindromes on the fly
            total_palindromes += (P[i] + 1) / 2;
        }

        return total_palindromes;
    }
};