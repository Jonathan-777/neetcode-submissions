
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        
        for (int i = 1; i <= rowIndex; i++) {
            int temp = ((long long)row.back() * ((rowIndex - i) + 1) / i  );

            row.push_back(temp);
        }
        return row;
    }
};


// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> row = {1};
        
//         for (int i = 1; i <= rowIndex; i++) {
//             // Cast row.back() to long long just for the math calculation!
//             long temp = ((long long)row.back() * ((rowIndex - i) + 1) / i);
            
//             row.push_back(temp);
//         }
//         return row;
//     }
// };