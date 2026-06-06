class Solution {
public:
    int ans = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 1){
                    int temp = 0;
                    helper(grid, i, j, temp);
                }
            }
        }
        return ans;
    }
    void helper(vector<vector<int>>& grid, int i , int j, int &curr_count){
        if(i >= grid.size() || j >= grid[i].size() || grid[i][j] != 1){
            return;
        }
        grid[i][j] = '*';
        curr_count++;
        ans = max(ans,curr_count);
        helper(grid,i + 1, j, curr_count);
        helper(grid,i -1, j , curr_count);
        helper(grid, i , j+1, curr_count);
        helper(grid, i , j-1, curr_count);

    }
};
