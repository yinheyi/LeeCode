#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        for (size_t i = 0; i < wordDict.size(); ++i) {
            wordSet.insert(wordDict[i]);
            maxLength = max(maxLength, wordDict[i].size());
        }

        vector<string> result;
        core(s, 0, result);
        return result;
    }

    bool core(const string& s, size_t start, vector<string>& result)
    {
        if (start == s.size()) {
            result.push_back("");
            return true;
        }

        if (pos2Strings.count(start) != 0) {
            result = pos2Strings[start];
            return true;
        }

        int curMaxLength = min(s.size() - start, maxLength);
        for (int length = 1; length <= curMaxLength; ++length) {
            string subStr = s.substr(start, length);
            vector<string> subResult;
            if (wordSet.count(subStr) == 1 && core(s, start + length, subResult)) {
                for (size_t i = 0; i < subResult.size(); ++i) {
                    result.push_back(subStr);
                    if (!subResult[i].empty()) {
                        result.back() += " ";
                        result.back() += subResult[i];
                    }
                }
            }
        }
        pos2Strings[start] = result;
        return !result.empty();
    }

private:
    unordered_map<size_t, vector<string>> pos2Strings;
    unordered_set<string> wordSet;
    size_t maxLength = 0;
};
