struct Trie{
    unordered_map<char, Trie*> children;
    bool endOfWord;
    Trie():endOfWord(false){

    }
};
struct TrieHelper{
    Trie* root = nullptr;

    TrieHelper(){
        root = new Trie();
    }

    bool insert_word_into_Trie(string s){
        Trie* temp = root;
        for(const auto& c : s){
            if(temp->children.find(c) == temp->children.end()){
                temp->children[c] = new Trie();
            }
            temp = temp->children[c];
        }
        if(!temp)return false;
        temp->endOfWord = true;
        return true;
    }

    bool word_search_in_Trie(string word){// option 1: pass string and indexes, or 2: pass in substring
        Trie* temp = root;

        for(const auto& c : word){
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

        int n  = s.size();
        TrieHelper Trie_dictionary{};
        int biggest_string = 0;
        vector<bool> dp(n, false);
        dp[n] = true;

        for(auto& word : wordDict){
           if(!Trie_dictionary.insert_word_into_Trie(word)){
            return false;
           }
           biggest_string = max(biggest_string, (int)word.size());
        }

        for(int i = n-1; i >= 0; --i){
            
            for(int j = i; j <= min(n-1, i + biggest_string-1); ++j){
                string  temp = s.substr(i, (j - i) + 1);
                if(!Trie_dictionary.word_search_in_Trie(temp))continue;
                dp[i] = dp[j + 1];

                if(dp[i]){
                    break;
                }
            }
        }

        return dp[0];

        
    }
};













