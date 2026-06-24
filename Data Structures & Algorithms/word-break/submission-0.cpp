class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }

    bool search(string& s, int i, int j) {
        TrieNode* node = root;
        for (int idx = i; idx <= j; ++idx) {
            if (!node->children.count(s[idx])) {
                return false;
            }
            node = node->children[s[idx]];
        }
        return node->is_word;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string word : wordDict) {
            trie.insert(word);
        }

        int n = s.length();
        vector<bool> dp(n , false);
        dp[n] = true;

        int maxLen = 0;
        for (string w : wordDict) {
            maxLen = max(maxLen, (int)w.size());
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < min(n, i + maxLen); ++j) {
                if (trie.search(s, i, j)) {
                    dp[i] = dp[j + 1];
                    if (dp[i]) break;
                }
            }
        }

        return dp[0];
    }
};













