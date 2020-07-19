class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        const int L = s1.size();
        vector<vector<vector<bool>>> bp(L, vector<vector<bool>>(L, vector<bool>(L + 1, false)));
        for (int i = L - 1; i >= 0; --i) {
            for (int j = L - 1; j >= 0; --j) {
                const int maxLength = min(L - i, L - j);
                for (int l = 1; l <= maxLength; ++l) {
                    if (l != 1) {
                        for (int firstLength = 1; firstLength < l; ++firstLength) {
                            bp[i][j][l] = bp[i][j][firstLength] && bp[i + firstLength][j + firstLength][l - firstLength]
                                         || bp[i][j + l - firstLength][firstLength] && bp[i + firstLength][j][l - firstLength];
                            if (bp[i][j][l]) {
                                break;
                            }
                        }
                    } else {
                        bp[i][j][l] = (s1[i] == s2[j]);
                    }
                }
            }
        }
        return bp[0][0][L];
    }
};
