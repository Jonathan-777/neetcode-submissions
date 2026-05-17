class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        auto search = [&](int pos){
            int l = 0; 
            int r = matrix[pos].size()-1;

            while(l <= r){
                int middle = (l + r) / 2;
                if(matrix[pos][middle] == target){
                    return true;
                }
                if(matrix[pos][middle] < target){
                    l = middle + 1;
                }
                if( matrix[pos][middle] > target){
                    r = middle -1;
                }
            }

            return (r == 1 &&  matrix[pos][r] == target)? true : false;
        };
        bool ans = false;

        for(int i = 0 ; i < matrix.size(); ++i){
            // if(matrix[i].size())
            int leftNUM = matrix[i][0];
            int rightNum = matrix[i][matrix[i].size()-1];

            if( leftNUM <= target  && target <= rightNum){
               return search(i);
               
            }
        }

        
        return ans;
        
    }
};
