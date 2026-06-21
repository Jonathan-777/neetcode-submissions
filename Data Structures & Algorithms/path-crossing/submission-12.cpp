class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set< pair<int, int>, pair_hash > visit;
        int x = 0, y = 0;
        visit.insert({x, y});

        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else if (c == 'W') x--;

            if (visit.count({x, y})) return true;
            visit.insert({x, y});
        }

        return false;
    }

private:
    struct pair_hash {
        template <typename T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {// hash<type>() returns 64 bit answer 
            return ( hash<T1>()(p.first) << 32) + (hash<T2>()(p.second)) ;
            
        }
    };
};