class Solution {
public:
    vector<vector<int>> v = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int r = board.size();
        int c = board[0].size();


        for(int i = 0 ; i < r; ++i){
            if(board[i][0] == 'O'){
                q.push({i,0});

            }
            if(board[i][c-1] == 'O'){
                q.push({i,c-1});
            }
        }
        for(int i = 0; i < c; ++i){
            if(board[0][i] == 'O'){
                q.push({0,i});
            }
            if(board[r-1][i] == 'O'){
                q.push({r-1,i});
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(board[i][j] == 'O')board[i][j] = '!';

            for(int z = 0 ; z < v.size(); ++z){
                int ROW = i + v[z][0];
                int COL = j + v[z][1];

                if(ROW < 0 || COL < 0 || ROW >= board.size() || COL >= board[0].size())continue;

                if(board[ROW][COL] == 'O'){
                    q.push({ROW,COL});
                }
            }
            
        }


        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '!'){
                    board[i][j] = 'O';
                }
                
            }
        }

        
    }
};
