class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int, char> m;
        char temp = 'A';
        for(int i = 1 ; i < 27; ++i){
            m[i] = temp++;
        }
        string ans = "";
   
        while(columnNumber >= 1){
            int range = columnNumber % 26;

            if(range == 0){// only when its 26/26
                range = 26;
                columnNumber -= 1;
            }
            ans = m[range] + ans;
     
            columnNumber =   columnNumber / 26;

        }
        return ans;
    }
};