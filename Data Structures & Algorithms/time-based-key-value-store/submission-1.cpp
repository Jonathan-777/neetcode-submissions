class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> m;// k , <time, str>
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});        
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end()) return "";
        int l = 0;
        int r = m[key].size()-1;
        pair <int, string> ans = {INT_MAX, ""};

        
        while(l <= r){
            int middle = l + (r - l) / 2;
            pair<int,string> candidate = { m[key][middle].first   , m[key][middle].second};

            if(candidate.first <= timestamp){
                ans = candidate;
            }

            if(candidate.first > timestamp){
                r = middle -1;
            }else{
                l = middle + 1;
            }


        }

        return (ans.first <= timestamp) ? ans.second : "";
    }
};
