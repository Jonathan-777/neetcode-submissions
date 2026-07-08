class CountSquares {
public:
    struct Pair_hash{
        template<typename T1, typename T2>
        size_t operator()(const pair<T1,T2>& p)const{// we must use const since the inbuilt unordered map structure expects it
            long h1 = hash<T1>{}(p.first);
            long h2 = hash<T2>{}(p.second);
            return h1 ^ (h2 + 0x933779b9 + (h1 << 6) + (h1 >> 2));
        }

    };
    unordered_map<pair<int,int>, int, Pair_hash> m;
    vector<vector<int>> v;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0], point[1]}]++;
        v.push_back({point[0], point[1]});
        
    }
    
    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];
        int ans  = 0;

        for(const auto& vec : v){
            int x_temp = vec[0];
            int y_temp = vec[1];
            
            if(abs(x - x_temp) != abs(y - y_temp) || x == x_temp )continue;// pick only diagonals

            ans += m[{x, y_temp}] * m[{x_temp,y}];// we only multiply the sides we know connect the diagonals together
            
        }

        return ans;
        
    }
};
