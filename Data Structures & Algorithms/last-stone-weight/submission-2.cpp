class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        

        while(stones.size() > 1){
            int idxZero = *stones.rbegin();
            int idxOne = *(stones.rbegin()+1);
            cout << idxZero << idxOne;

            idxZero = abs(idxZero - idxOne);

            stones.erase(stones.rbegin().base() - 2);
            stones.erase(stones.rbegin().base() - 1);
            if(idxZero != 0){
                stones.push_back(idxZero);
                sort(stones.begin(), stones.end());
            }
            

        }
        return (stones.empty()) ? 0 : *stones.begin();
    }
};
