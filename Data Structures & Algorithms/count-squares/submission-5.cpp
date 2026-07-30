class CountSquares {
public:
    struct Functor{
        template<typename T1, typename T2>
        size_t operator()( const pair<T1, T2>&  p)const noexcept{
            return (hash<T1>()(p.first * 1L ) << 32) + hash<T2>()(p.second);
            
        }
    };
    

    CountSquares() {
        
    }

    unordered_map<pair<int,int>, int, Functor> coordinates;
    vector<pair<int,int>> v;// is there a better structure for this? faster? unordered_set of pairs?
    
    void add(vector<int> point) {
        coordinates[{point[0], point[1]}]++;
        v.push_back({point[0], point[1]});
        
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(const auto& [x1, y1] : v){

            if(abs(x1 - x) != abs(y1 - y) || x == x1  || y == y1 )continue;// finds diagonals

            ans += coordinates[{x1, y}] * coordinates[{x, y1}];
        }
        return ans;
    }
};
