class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 1;
        std::queue<string> qq;
        std::queue<string> pp;
        qq.push(beginWord);
        while (!qq.empty() || !pp.empty()) {
            std::queue<string>& q1 = !qq.empty() ? qq : pp;
            std::queue<string>& q2 = qq.empty() ? qq : pp;
            while (!q1.empty()) {
                const string& top = q1.front();
                if (top == endWord) {
                    return step;
                }
                for (int i = 0; i < wordList.size(); /* */) {
                    if (IsMatch(top, wordList[i])) {
                        q2.push(wordList[i]);
                        swap(wordList[i], wordList.back());
                        wordList.pop_back();
                        continue;
                    }
                    ++i;
                }
                q1.pop();
            }
            ++step;
        }
        return 0;
    }

private:
    bool IsMatch(const string& str1, const string& str2)
    {
        if (str1.size() != str2.size()) {
            return false;
        }

        size_t diff = 0;
        for (size_t i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }
};
