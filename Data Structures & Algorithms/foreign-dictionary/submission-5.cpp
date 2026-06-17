class Solution {
public:
    string foreignDictionary(vector<string>& words) {// khan's algorithm
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> adj;// set will avoid duplicate rules, actually this will just save runtime performance*********
        queue<char> q;
        int size = words.size();
        string ans = "";
            for(auto word : words){  // must keep count of all unique chars
                    for(auto c : word){
                        indegree[c] = 0;
                    }
            }
        for(int i = 0; i < size -1; ++i){// determine lexicographical order and handle edge case
            string curr = words[i];
            string after_curr = words[i+1];
            int smallest = min(curr.size(), after_curr.size());
            if(curr.substr(0,smallest) == after_curr.substr(0,smallest) && curr.size() > after_curr.size() ){// this avoids 1 for loop
                return "";
            }
            // we can avoid another for loop *yes
            //mismatch function?
            auto [it_curr, it_after_curr] = mismatch(curr.begin(), curr.end(), after_curr.begin(), after_curr.end());
            if(it_curr == curr.end() || it_after_curr == after_curr.end()){
                // do nothing / continue
                continue;
            }
            if(!adj[*it_curr].count(*it_after_curr)){
                adj[*it_curr].insert(*it_after_curr);
                indegree[*it_after_curr]++; 
            }
                      
        }

        for(auto [k,v] : indegree){
            if(v == 0){
                q.push(k);
            }
        }

        while(!q.empty()){
            char curr = q.front();
            q.pop();
            ans += curr;
            if(!adj.contains(curr))continue;
            for(auto temp : adj[curr]){
                
                indegree[temp]--;
                if(indegree[temp] == 0){// it can ony be 0 once
                    q.push(temp);
                }
            }
        }


         return (ans.size() == indegree.size())? ans : "";


        
    }
};
