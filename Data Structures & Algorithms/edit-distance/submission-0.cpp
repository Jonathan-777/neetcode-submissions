class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // Create a 2D matrix of size (m + 1) x (n + 1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Base case: Bottom row (word1 is empty)
        // Cost is inserting the remaining characters of word2
        for (int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }

        // Base case: Rightmost column (word2 is empty)
        // Cost is deleting the remaining characters of word1
        for (int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }

        // Fill the matrix from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                if (word1[i] == word2[j]) {
                    // Characters match: take the diagonal value
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // Characters differ: take the cheapest operation + 1
                    dp[i][j] = 1 + min({ 
                        dp[i + 1][j],     // Delete (look below)
                        dp[i][j + 1],     // Insert (look right)
                        dp[i + 1][j + 1]  // Replace (look diagonal)
                    });
                }
                
            }
        }

        // The top-left cell holds the total cost for the full strings
        return dp[0][0];
    }
};