// must create our own trienode since its not given 

struct TrieNode{
    unordered_map<char , TrieNode*> children ;
    bool endOfWord = false;

};

class PrefixTree {
public:
    TrieNode* root = nullptr;//global scope
    PrefixTree() {
        root = new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto w : word){
            if(temp->children.find(w) == temp->children.end()){// c doesnt exist
                temp->children[w] = new TrieNode();
                temp = temp->children[w];
                continue;
            }
            temp = temp->children[w];               // c exist
        }

        temp->endOfWord = true;
        return;        
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for( auto w : word){
            if(temp->children.find(w) == temp->children.end()){
                return false;
            }
            temp = temp->children[w];
        } 
        return (temp->endOfWord);
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto p : prefix){
            if(temp->children.find(p) == temp->children.end()){
                return false;
            }
            temp = temp->children[p];

        }
        
        return true;
    }
};
