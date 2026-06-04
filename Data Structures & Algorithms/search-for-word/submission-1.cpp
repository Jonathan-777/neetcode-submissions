class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0 ; i < board.size(); ++i){
            for(int j = 0 ; j < board[i].size(); ++j){
                if(board[i][j] != word[0])continue;
                if(helper(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;

    }

    bool helper(vector<vector<char>>& board, string word, int i, int j, int word_index ){
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || word_index >= word.size() || board[i][j] != word[word_index] || board[i][j] == '*'){
            return false;
        }
        if(word_index == word.size()-1)return true;

        char curr = word[word_index];
        board[i][j] = '*';
        
        bool sentinel = (
            helper(board, word, i + 1, j, word_index + 1) ||
            helper(board, word, i - 1, j, word_index + 1) ||
            helper(board, word, i, j + 1, word_index + 1) ||
            helper(board, word, i, j - 1, word_index + 1)
        );


        board[i][j] = curr;
        return sentinel;

    }
};
