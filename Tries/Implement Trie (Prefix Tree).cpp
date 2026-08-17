class Trie {
    Trie* children[26];
    bool is_end;
public:
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        is_end = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            // cout << c << "\n";
            int idx = c - 'a';
            // cout << idx << "\n";
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie(); //BUG: not add node-> alter this->children
            }
            node = node->children[idx];
        }
        node->is_end = true;
        
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return (node->is_end);

        
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */