class Solution {
public:
    vector<vector<int>> deltas = {{0,1}, {1,0}};
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n,1));
        queue<pair<int,int>> q;
        
        q.push({0,0});
        int ans = 0;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto & delta : deltas){
                int ROW = delta[0] + r;
                int COL = delta[1] + c;

                if(ROW < 0 || COL < 0 || ROW >= m || COL >= n || matrix[ROW][COL] != 1)continue;
                int left = (ROW - 1 >= 0) ? matrix[ROW - 1][COL] : 0;
                int up = (COL - 1 >= 0) ? matrix[ROW][COL - 1] : 0;
                matrix[ROW][COL] = up + left;
                q.push({ROW,COL});

            }
        }
        return matrix[m-1][n-1];
    }
};
