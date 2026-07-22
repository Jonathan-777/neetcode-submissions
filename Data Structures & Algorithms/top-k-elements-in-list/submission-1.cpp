class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;

        for(int& x : nums){
            m[x]++;
        }

        for(auto& [key, val] : m){
            pq.push({val, key});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;

        for(int i = 0; i < k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
