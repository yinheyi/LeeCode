struct Info {
    char ch =' ';
    size_t index = -1;
    Info(char ch_, size_t index_) : ch(ch_), index(index_) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<Info> InfoStack;
        int maxLength = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (InfoStack.empty()) {
                InfoStack.push(Info(s[i], i));
                continue;
            }

            if (s[i] == '(') {
                InfoStack.push(Info(s[i], i));
                continue;
            }

            if (InfoStack.top().ch == '(') {
                InfoStack.pop();
                const int curValue = InfoStack.empty() ? (i + 1) : (i - InfoStack.top().index);
                maxLength = maxLength < curValue ? curValue : maxLength;
            } else {
                InfoStack.push(Info(s[i], i));
            }
        }
        return maxLength;
    }
};
