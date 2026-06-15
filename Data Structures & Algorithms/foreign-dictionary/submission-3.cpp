class Solution {
public:
    string foreignDictionary(vector<string>& words) {// khans algorithm approach
        unordered_map<char,int> indegree;
        unordered_map<char, unordered_set<char>> adj;
        int size = words.size();
        queue<char> q;
        
        string ans = "";

        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for(int i = 0; i < size-1 ; ++i){
            string curr = words[i];
            string after_curr = words[i+1];
            int smallest_word_size = min(curr.size(), after_curr.size());
            if((curr.substr(0,smallest_word_size) == after_curr.substr(0, smallest_word_size)) && curr.size() > after_curr.size()){
                return "";// we cannot determine if the claim is true
            }
            auto [curr_it, after_curr_it] = mismatch(curr.begin(), curr.end(), after_curr.begin(), after_curr.end());
            if(curr_it != curr.end() && after_curr_it != after_curr.end() &&!adj[*curr_it].count(*after_curr_it))
                indegree[*after_curr_it]++;
                adj[*curr_it].insert(*after_curr_it);

        }

        for(auto [k,v] : indegree){
            if(v == 0){
                q.push(k);
            }
        }
        while( !q.empty() ){
            char curr = q.front();
            q.pop();
            ans += (curr);
            for(auto c : adj[curr]){
                indegree[c]--;
                if(indegree[c] == 0){
                    q.push(c);
                }
            }

        }


        return (ans.size() == indegree.size())? ans : "";
    }
};
