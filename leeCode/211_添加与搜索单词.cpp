#include <string>

using namespace std;

class Trie {
public:
    Trie() {
        root = new TreeNode;
    }

    virtual ~Trie() {
        FreeNode(root);
    }
    
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

protected:
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

class WordDictionary : public Trie {
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        insert(word);
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }

private:
    bool search(TreeNode* curNode, const string& word, size_t index) {
        if (word[index] == '.') {
            for (size_t i = 0; i < 26; ++i) {
                if (curNode->children[i] == nullptr) {
                    continue;
                }
                if (index == word.size() - 1 && curNode->children[i]->isEnd) {
                    return true;
                }
                if (index != word.size() - 1 && search(curNode->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (curNode->children[word[index] - 'a'] == nullptr) {
                return false;
            }
            if (index == word.size() - 1) {
                return curNode->children[word[index] - 'a']->isEnd;
            }
            return search(curNode->children[word[index] - 'a'], word, index + 1);
        }
    }
};


