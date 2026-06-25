struct Trie{
    unordered_map<char, Trie*> children;
    bool endOfWord;
    Trie():endOfWord(false){

    }

};

struct Trie_helper{
    Trie* root = nullptr;

    Trie_helper(){
        root = new Trie();
    }

    bool insert_word(string word){
        Trie* temp = root;
        for(auto c : word){
            if(temp->children.find(c) == temp->children.end()){
                temp->children[c] = new Trie();
            }
            temp = temp->children[c];
        }
        if(!temp)return false;
        temp->endOfWord = true;
        return temp->endOfWord;
    }

    bool find_word(string word){
        Trie* temp = root;
        for(auto c : word){
            if(temp->children.find(c) == temp->children.end()){
                return false;
            }
            temp = temp->children[c];
        }
        return temp->endOfWord;
    }

};



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        Trie_helper dictionary{};
        vector<bool> dp(n+1,false);
        dp[n] = true;
        int longest_length = 0;
        for(const auto word : wordDict){
            if(!dictionary.insert_word(word))return false;
            longest_length = max(longest_length, (int)word.size());
        }

        for(int i = n-1 ; i >= 0; --i){
            for(int j = i; j <= min(n-1, i + longest_length); j++){
                string temp = s.substr(i, ( j- i) + 1);

                if(!dictionary.find_word(temp))continue;
                    dp[i] = dp[j+1];
                    if(dp[i]){
                        break;
                    }
                
            }
        }
        return dp[0];
    }
};














