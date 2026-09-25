class Solution {
public:
    struct Overload{
        template<typename T1, typename T2>
        size_t operator()(pair<T1,T2> p)const noexcept{
            return (hash<T1>{}(p.first * 1L<< 32) + hash<T2>{}(p.second));
        }

    };
    bool isPathCrossing(string path) {
        int up = 0;
        int right = 0;

        unordered_set<pair<int,int>, Overload> s;

        s.insert({up,right});// we start visiting orign

        for(const auto& c : path){

            if( c == 'N'){
                up++;
            }else if( c == 'S'){
                up--;
            }else if( c == 'W'){
                right--;
            }else{
                right++;
            }
            if(!s.insert({up,right}).second){
                return true;
            }
        }
        return false;
    }
};