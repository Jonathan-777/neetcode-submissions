class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        int size = 1;

        for(int i = 1; i <= rowIndex; i++){
            triangle.push_back(vector<int>(size+1, 0));

            for(int j = 0; j < triangle[i].size(); j++){
                if(j == 0 || j == triangle[i].size() - 1){
                    triangle[i][j] = 1;
                } else {
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
                }
            }

            size++;
        }

        return triangle[rowIndex];
    }
};