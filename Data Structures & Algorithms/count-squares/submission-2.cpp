class CountSquares {
public:
    CountSquares() {
        
    }
    unordered_map<size_t, int> m;
    vector<vector<int>> v;

    size_t encrypt_coordinate(int x, int y){
        long h1 = hash<int>{}(x);
        long h2 = hash<int>{}(y);
        return (h1 << 32) + h2;
    }
    
    void add(vector<int> point) {
        m[encrypt_coordinate(point[0], point[1])]++;
        v.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(const auto& vec : v){
            int x1 = vec[0];
            int y1 = vec[1];
            if(x1 == x || y == y1 || abs(x - x1) != abs(y - y1) )continue;

            ans += m[encrypt_coordinate(x,y1)] * m[encrypt_coordinate(x1,y)];
        }
     return ans;   
    }
};
