class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = "#" + word1;
        word2 = "#" + word2;
        vector<vector<int>> bp(word1.size(), vector<int>(word2.size(), word1.size() + word2.size()));
        for (size_t i = 0; i < word1.size(); ++i) {
            for (size_t j = 0; j < word2.size(); ++j) {
                if (i == 0 && j == 0) {
                    bp[i][j] = 0;
                    continue;
                }

                if (i == 0) {
                    bp[i][j] = j;
                    continue;
                }

                if (j == 0) {
                    bp[i][j] = i;
                    continue;
                }

                bp[i][j] = min(bp[i-1][j], bp[i][j-1]) + 1;
                bp[i][j] = min(bp[i][j], bp[i-1][j-1] + ((word1[i] == word2[j]) ? 0 : 1));
            }
        }
        return bp.back().back();
    }
};
