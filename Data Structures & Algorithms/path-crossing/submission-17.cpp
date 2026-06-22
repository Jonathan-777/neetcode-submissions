struct Pair_insert{
    template<typename T1, typename T2>
    size_t operator()(const pair<T1,T2>& p)const noexcept( noexcept(hash<T1>{}(p.first)) && noexcept(hash<T2>{}(p.second))){// both const are required to avoid mutability
        return ((hash<T1>()(p.first) << 32) + (hash<T2>()(p.second)));
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int,int> , Pair_insert> container;

        int up = 0;
        int right = 0;
        container.insert({up,right});
        

        for(int c : path){
            if(c == 'N'){
                up++;
            }else if(c == 'E'){
                right++;
            }else if( c == 'S'){
                up--;
            }else{
                right--;
            }

            if(!container.insert({up, right}).second){
                return true;
            }
        }
        return false;
    }
    
};