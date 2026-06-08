class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ans=0; 
        int fresh = 0;

        for(int i = 0 ; i < grid.size(); ++i){
            for(int j = 0 ; j < grid[i].size(); ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                 if(grid[i][j] == 1)fresh++;
            }
        }

        vector<vector<int>> v = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int k = 0 ; k < size; ++k){
                auto [i,j] = q.front();
                q.pop();

                for(int z = 0 ; z < v.size(); ++z){
                    int  ROW = i + v[z][0];
                    int  COL = j + v[z][1];

                    if(ROW < 0 || COL < 0 || ROW >= grid.size() || COL >= grid[i].size())continue;

                    if(grid[ROW][COL] != 1)continue;
                    grid[ROW][COL] = 2;
                    fresh--;
                    q.push({ROW,COL});

                }
            }
            ans++; 
        }
        return (fresh > 0) ? -1 : ans;
    }
};
