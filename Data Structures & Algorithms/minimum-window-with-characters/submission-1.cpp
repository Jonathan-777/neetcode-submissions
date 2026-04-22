class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> ms;
        unordered_map<char,int>mt;
        int l = 0;
        string ans = s + "hello";
        queue<int> q;
        int have  = 0;

        for(int i = 0; i < t.size(); ++i){
            mt[t[i]]++;
        }

        for(int i = 0; i < s.size(); ++i){  
            char curr = s[i];
            
            
            if(mt.find(curr) != mt.end()){
                ms[curr]++;
                q.push(i);
            }

            if(mt.find(curr) != mt.end() && mt[curr] == ms[curr]){
                have++;
            }


            while(have == mt.size()){
                // window is valid
                string candidate = s.substr(q.front(), i - q.front() + 1);
                if( ans.size() > candidate.size()){
                    ans = candidate; 
                }
                ms[s[q.front()]]--;
                if(ms[s[q.front()]] < mt[s[q.front()]]) have--;

                q.pop();
                

            }
            

        }
        cout << ans;
        
        return (ans.size() > s.size()) ? "" : ans;
    }
};
