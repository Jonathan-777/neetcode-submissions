class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int curr = 1;
        vector<vector<int>> ANS = {{1}};
      

        while(curr <= rowIndex){
            vector<int> temp(ANS[curr-1].size()+1,1);

            for(int i = 0; i < temp.size(); ++i){
                int aboveLeft = (i-1 >= 0 && i - 1  < ANS[curr-1].size())       ?  ANS[curr-1][i-1] : 0;
                int above =     (i >=   0 && i  < ANS[curr-1].size())      ?   ANS[curr-1][i] : 0;


                temp[i] = aboveLeft + above;
            }
            ANS.push_back(temp);
            curr++;
        }
        return ANS[ANS.size()-1];
    }
};