class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // dp[i][j] stores the max square side length ending at (i-1, j-1)
        // We use an extra row and column (1-indexed) to cleanly handle grid boundaries
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int maxSide = 0;
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    // Constrained by the smallest surrounding square
                    dp[i][j] = min({dp[i - 1][j] ,   dp[i][j - 1],   dp[i - 1][j - 1] }) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        // Return the area (side * side)
        return maxSide * maxSide;
    }
};