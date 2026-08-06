class CountSquares {
public:
    struct Hash{
        template<typename T1, typename T2>
        size_t operator()( const pair<T1, T2>&  p)const noexcept{
            return (hash<T1>()(p.first * 1L ) << 32) + hash<T2>()(p.second);
            
        }
    };
    CountSquares() {
        
    }
    unordered_map<pair<int,int>, int ,Hash > squares;
    vector<pair<int,int>> v;

    
    void add(vector<int> point) {
        v.push_back({point[0], point[1]});
        squares[v.back()]++;
    }
    
    int count(vector<int> point) {
        int x  = point[0];
        int y = point[1];
        int ans = 0;
        
        for(const auto& [x1,y1] : v){
            if(abs(x - x1) != abs(y - y1) || x == x1)continue;

            ans += squares[{x, y1}] * squares[{x1, y}];
        }
        return ans;
    }
};
