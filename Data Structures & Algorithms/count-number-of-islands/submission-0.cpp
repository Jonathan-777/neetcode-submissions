class Solution {
public:
    int ans = 0;
    int numIslands(vector<vector<char>>& grid) {

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == '1'){
                    helper(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void helper(vector<vector<char>>& grid, int i , int j ){
        if(i >= grid.size() || j >= grid[i].size() || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '*';

        helper(grid,i+1, j);
        helper(grid,i-1, j);
        helper(grid,i, j+1);
        helper(grid,i, j-1);
    }
};
