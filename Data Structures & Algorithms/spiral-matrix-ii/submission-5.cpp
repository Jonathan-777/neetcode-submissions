class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int x = 1;
        vector<vector<int>> v(n, vector<int>(n,-1));//sentiel value
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int index = 0;

        queue<pair<int,int>> q;
        q.push({0,0});
        v[0][0] = x;

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();

            if(x == n * n)break;

            int  ROW = r + directions[index][0];
            int  COL = c + directions[index][1];
            

            if( ROW < 0  || COL < 0 || ROW >= n || COL >= n || v[ROW][COL] != -1){
                index = (index + 1 )% 4;
                ROW = r + directions[index][0];
                COL = c + directions[index][1];
            }

            v[ROW][COL] = ++x;
            q.push({ROW,COL});


        }
        
        return v;
    }
};