class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        size_t lastAlphaIndex = -1;
        for (size_t i = s.size(); i > 0; --i) {
            if (s[i-1] != ' ') {
                lastAlphaIndex = i - 1;
                break;
            }
        }
        if (lastAlphaIndex == -1) {
            return 0;
        }

        size_t lastSpaceIndex = -1;
        for (size_t i = lastAlphaIndex; i > 0; --i) {
            if (s[i-1] == ' ') {
                lastSpaceIndex = i - 1;
                break;
            }
        }

        if (lastSpaceIndex == -1) {
            return lastAlphaIndex + 1;
        } else {
            return lastAlphaIndex - lastSpaceIndex;
        }
    }
};
