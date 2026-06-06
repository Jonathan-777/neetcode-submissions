struct Trie{
    unordered_map<char , Trie*> children;
    bool endOfWord;

};

class WordDictionary {
public:
    Trie* root = nullptr;
    WordDictionary() {
        root = new Trie();
        
    }
    
    void addWord(string word) {
        Trie* temp = root;
        for(auto w : word){
            if(temp->children.find(w) == temp->children.end()){
                temp->children[w] = new Trie();
            }
            temp = temp->children[w];
        }
        temp->endOfWord = true;
        
    }
    
    bool search(string word) {

        auto recurse = [&](auto& self, int index, Trie* curr){
            if(index == word.size()){
                return curr->endOfWord;
            }

            char c = word[index];

            if(c == '.' && !curr->children.empty()){
                for(auto m : curr->children){
                    if(self(self, index+1, m.second)){
                        return true;
                    }
                    
                }
                return false;

            }else{
                if(curr->children.empty() || curr->children.find(c) == curr->children.end()){
                    return false;
                }
                return self(self,index+1, curr->children[c]);
                
            }
            
        };
       return recurse(recurse,0,root);
    }
};
