class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int l = 0;
        int r = COLS - 1;
        int row = 0;

        while(row < ROWS){

            if(matrix[row][r] >= target && matrix[row][l] <= target){
                while(l <= r){
                    int mid = l + (r-l)/2;

                    if(matrix[row][mid] == target){
                        return true;
                    } else if(matrix[row][mid] > target){
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                return false;
            } else if(matrix[row][r] < target){
                row++;
            } else{
                return false;
            }
        }
        return false;
    }
};
