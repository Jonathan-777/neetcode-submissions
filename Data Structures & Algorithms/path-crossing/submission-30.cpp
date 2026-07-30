class Solution {
public:

    struct Functor{
            template<typename T1, typename T2>
        size_t operator()(pair<T1,T2> p)const noexcept(noexcept(hash<int>{}(p.first)) &&  noexcept(hash<int>{}(p.second))){
            return hash<int>()(p.first * 1L) << 32 + hash<int>()(p.second);
        }

    } ;
    bool isPathCrossing(string path) {

        unordered_set<pair<int,int>, Functor> s;
        int vertical = 0;
        int horizontal = 0;
        s.insert({vertical,horizontal});

        for(const auto& c : path){
            if( c == 'N'){
                vertical++;
            }else if(c == 'S'){
                vertical--;
            }else if(c == 'W'){
                horizontal++;
            }else{
                horizontal--;
            }
            if(!s.insert({vertical,horizontal}).second)return true;
        }
        return false;
    }
};