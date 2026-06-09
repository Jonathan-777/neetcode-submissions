class Solution {
public:
     vector<vector<int>> v = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int r = heights.size();
        int c = heights[0].size();
        queue<pair<int,int>> atlantic_Q;
        queue<pair<int,int>> pacific_Q;
        vector<vector<bool>> atlantic_matrix(r, vector<bool>(c, false));
        vector<vector<bool>> pacific_matrix(r, vector<bool>(c,false));

        for(int i = 0 ; i < r; ++i){
            atlantic_Q.push({i, c-1});
            pacific_Q.push({i, 0});
        }
        for(int i = 0; i < c; ++i){
            atlantic_Q.push({r-1, i});
            pacific_Q.push({0, i});
        }

        bfs(heights, pacific_matrix,pacific_Q);
        bfs(heights, atlantic_matrix, atlantic_Q);

        for(int i = 0 ; i < r ; ++i){
            for(int j = 0 ; j < c; ++j){
                if(atlantic_matrix[i][j] && pacific_matrix[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;


        
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean_matrix, queue<pair<int,int>>& q ){
        
        

        while(!q.empty()){
            auto [i,j] = q.front();
            ocean_matrix[i][j] = true;
            q.pop();

            for(int z = 0 ; z < v.size(); ++z){
                int ROW = i + v[z][0];
                int COL = j + v[z][1];

                if(ROW >= 0 && COL >= 0 && ROW < heights.size() && COL < heights[0].size() && ocean_matrix[ROW][COL] != true && heights[ROW][COL] >= heights[i][j]){
                    q.push({ROW,COL});
                }

            }
            
        }

    }
};
