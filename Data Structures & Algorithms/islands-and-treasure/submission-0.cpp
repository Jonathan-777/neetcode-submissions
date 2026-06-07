class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {// m* n solution
        // 1. add 0's to queue
        // traverse l-r up-down and add those cells surrounding 0 to queue(what if they are all -1?, then that means its imossible to traverse )
        // add the traversable new distances to the queue and repeat
        // done
        queue<pair<int,int>> q;
        for(int i = 0 ; i < grid.size(); ++i){  // m * n
            for(int j = 0 ; j < grid[i].size(); ++j){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>v = {{0,-1}, {-1,0} , {0,1}, {1,0}};

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int z = 0; z < v.size(); ++z){
                int ROW = v[z][0];
                int COL = v[z][1];

                if(i+ROW >= grid.size() || j+COL >= grid[i].size() || i + ROW < 0 || j+COL < 0)continue;// out of bounds

                int curr = grid[i + ROW][j + COL];
                if(curr != 2147483647)continue;// we are guaranteed to reach the minimal distance first, so there is no need for double checks after we remove Inf, where INF = 2147483647

                if(curr != -1 && curr != 0){
                    q.push({i + ROW, j + COL});
                }

                if(i+ROW < grid.size() && j+COL < grid[i].size() && curr != -1 && curr != 0){
                    grid[i + ROW][j + COL] = min(grid[i+ROW][j+COL], grid[i][j] + 1);
                    
                }

                
            }

            
        }

        
    }


};
