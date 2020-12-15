#include <string>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TreeNode;
    }

    ~Trie() {
        FreeNode(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* cursor = root;
        for (size_t i = 0; i < word.size(); ++i) {
            if (cursor->children[word[i] - 'a'] == nullptr) {
                cursor->children[word[i] - 'a'] = new TreeNode;
            }

            if (i == word.size() - 1) {
                cursor->children[word[i] - 'a']->isEnd = true;
            }

            cursor = cursor->children[word[i] - 'a'];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* cursor = root;
        for (size_t i = 0; i < word.size(); ++i) {
            if (cursor->children[word[i] - 'a'] == nullptr) {
                return false;
            }
            if ( i == word.size() - 1) {
                return cursor->children[word[i] - 'a']->isEnd; 
            }
            cursor = cursor->children[word[i] - 'a'];
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* cursor = root;
        for (size_t i = 0; i < prefix.size(); ++i) {
            if (cursor->children[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            cursor = cursor->children[prefix[i] - 'a'];
        }
        return true;
    }

private:
    struct TreeNode {
        bool isEnd = false;
        TreeNode* children[26] = { nullptr };
    };

    void FreeNode(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        for (size_t i = 0; i < 26; ++i) {
            FreeNode(node->children[i]);
        }
        delete node;
    }

    TreeNode* root = nullptr;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
