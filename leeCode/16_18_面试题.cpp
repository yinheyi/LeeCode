class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int aNum = 0;
        int bNum = 0;
        for (size_t i = 0; i < pattern.size(); ++i) {
            pattern[i] == a ? ++aNum : ++bNum;
        }

        const int strLength = value.size();
        const int maxALength = aNum == 0 ? 0 : strLength / aNum;
        const int maxBLength = bNum == 0 ? 0 : strLength / bNum;

        for (int curALength = 0; curALength <= maxALength; ++ curALength) {
            for (int curBLength = 0; curBLength <= maxBLength; ++curBLength) {
                if (curALength * aNum + curBLength * bNum != strLength) {
                    continue;
                }

                string aString = "#";
                string bString = "#";
                size_t curIndex = 0;
                for (size_t i = 0; i < pattern.size(); ++i) {
                    if (pattern[i] == 'a') {
                        if (aString == "#") {
                            aString = value.substr(curIndex, curALength);
                            curIndex += curALength;
                            continue;
                        } else {
                            if (value.substr(curIndex, curALength) != aString) {
                                break;
                            }
                            curIndex += curALength;
                        }
                    } else {
                        if (bString == "#") {
                            bString = value.substr(curIndex, curBLength);
                            curIndex += curBLength;
                            continue;
                        } else {
                            if (value.substr(curIndex, curBLength) != bString) {
                                break;
                            }
                            curIndex += curBLength;
                        }
                    }
                }
                if (curIndex == value.size() && aString != bString) {
                    return true;
                }
            }

        }
        return false;
    }
};
