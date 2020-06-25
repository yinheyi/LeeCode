class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<size_t> lengths;
        set<string> words;
        for (size_t i = 0; i < wordDict.size(); ++i) {
            lengths.insert(wordDict[i].size());
            words.insert(wordDict[i]);
        }

        vector<bool> table(s.size(), false);
        for (size_t i = 0; i < s.size(); ++i) {
            for (set<size_t>::iterator iter = lengths.begin(); iter != lengths.end(); ++iter) {
                if (*iter > i + 1 || table[i]) {
                    break;
                }

                if (*iter == i + 1) {
                    table[i] = words.count(s.substr(0, i +1)) == 1;
                } else {
                    table[i] = table[i - *iter] && words.count(s.substr(i - *iter + 1, *iter)) == 1;
                }
            }
        }
        return table.back();
    }
};
