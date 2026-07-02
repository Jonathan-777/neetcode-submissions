class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,-1));
        int x = 1;
        vector<vector<int>> movement = {{0, 1}, { 1,0}, { 0, -1}, {-1,0}};// order will be right, down, left,up
        queue<pair<int,int>> q;
        q.push({0,0});
        int idx = 0;
        v[0][0] = 1;

        while(!q.empty()){
            auto [ r,c] = q.front();
            q.pop();
            // v[r][c] = ++x;

            if(x == n*n) break;

            int ROW = r + movement[idx][0];
            int COL = c + movement[idx][1];

            if(ROW < 0 || COL < 0 || ROW >= n || COL >= n || v[ROW][COL] != -1){
                idx = (idx + 1) % 4; // flip 90 degrees counter clockwise
                ROW = r + movement[idx][0];
                COL = c + movement[idx][1];
            }

            
            
            q.push({ROW,COL});
            v[ROW][COL] = ++x;
            

        }

        return v;
        
    }


    
};