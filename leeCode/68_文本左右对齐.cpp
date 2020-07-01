class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        for (size_t i = 0; i < words.size(); ++i) {
            if (output.empty()) {
                output.push_back(words[i]);
                continue;
            }

            int remainer = maxWidth - (int)(output.back().size()) - 1;
            if ((int)(words[i].size()) <= remainer) {
                output.back() += " ";
                output.back() += words[i];
                continue;
            }
            output.push_back(words[i]);
        }

        for (size_t i = 0; i < output.size() - 1; ++i) {
            string& curStr = output[i];
            int spaceNum = 0;
            int remainer = maxWidth - (int)(curStr.size());
            for (size_t i = 0; i < curStr.size(); ++i) {
                if (curStr[i] == ' ') {
                    ++spaceNum;
                }
            }

            if (remainer == 0) {
                continue;
            }
            if (spaceNum == 0) {
                while (curStr.size() < maxWidth) {
                    curStr.push_back(' ');
                }
                continue;
            }

            vector<int> spaceTable(spaceNum, 1 + remainer / spaceNum);
            remainer %= spaceNum;
            for (int i = 0; i < remainer; ++i) {
                ++spaceTable[i];
            }

            string strstr;
            int num = 0;
            for (size_t i = 0; i < curStr.size(); ++i) {
                if (curStr[i] == ' ') {
                    for (int i = 0; i <spaceTable[num]; ++i) {
                        strstr.push_back(' ');
                    }
                    ++num;
                    continue;
                }
                strstr.push_back(curStr[i]);
            }
            curStr = strstr;
        }

        while (output.back().size() != maxWidth) {
            output.back().push_back(' ');
        }
        return output;
    }
};
