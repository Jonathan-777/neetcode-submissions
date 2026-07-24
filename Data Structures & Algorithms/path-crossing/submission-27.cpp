class Solution {
public:
    struct Comp{
        template<typename T1, typename T2>
        
        size_t operator()(pair<T1,T2> p)const noexcept(noexcept( hash<int>{}(p.first)) && noexcept( hash<int>{}(p.second))){
            size_t h = (hash<T1>()(p.first) << 32) + (hash<T2>()(p.second));
            return h;
        }
    };
    bool isPathCrossing(string path) {

        int up = 0;
        int horizontal = 0;
        unordered_set<pair<int,int>, Comp> s;
        
        s.insert({up,horizontal});

        for( const auto& c : path){

            if(c == 'N'){
                up++;
            }else if( c == 'S'){
                up--;
            }else if( c == 'W'){
                horizontal++;
            }else{
                horizontal--;
            }

            if(!s.insert({up,horizontal}).second){
                return true;
            }

        }
        return false;
    }
};