class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;

        for(auto c : arr){
            m[c]++;
        }

        for(auto c : arr){
            
            if(k == 1 && m[c] == 1){
                return c;
            }
            if(m[c] == 1){
                k--;
            }
        }
        return (k > 0) ? "" : arr[0];
    }
};