class CountSquares {
public:
    struct Functor{
        template<typename T1, typename T2>
        size_t operator()(pair<T1, T2> p)const noexcept{
            return hash<T1>()(p.first * 1ULL << 32) + hash<T2>()(p.second);
        }
    };  
    CountSquares() {
        
    }

    unordered_map<pair<int,int>, int, Functor> m;
    vector<vector<int>> v;
    
    void add(vector<int> point) {
        m[{point[0], point[1]}]++;
        v.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(const auto& vec : v){
            int x1 = vec[0];
            int y1 = vec[1];
            if(x == x1 || y == y1 ||(abs(x - x1) != abs(y - y1)))continue;
            ans += m[{x,y1}] * m[{x1, y}];
        }
        return ans;
    }
};
